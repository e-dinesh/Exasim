function avField = avfieldPhysical2d_Di(u, q, w, v, x, t, mu, eta, nspecies, nd)
    % Mutation outputs
    p = eta(1);
    gam = eta(2);
%     avk_b_coeff = eta(3);

    gam1 = gam - 1;
    nenergy = 1;
    ncu = nspecies + nd + nenergy;
    % artificial viscosity
    porder = mu(15);

    % regularization parameters for the bulk viscosity
    kb = mu(16);
    sb0   = mu(17); %0.02 
    sbmin = 0.0;
    sbmax = mu(18);% / sqrt(gam*gam - 1.0); %2.5 TODO: unsure that this should be changing 
    kD = 1.0;

    % regularization parameters
    alpha = mu(22);
    rmin = 0.0;
    Hmin = 1.0e-4;

    % mesh size
    hm = v(7);

    % Get base variables
    rho_i = u(1:nspecies);
    rhou = u(nspecies+1);
    rhov = u(nspecies+2);
    rhoE = u(nspecies+3);

    % Regularization 
    rho_i = rmin + lmax(rho_i-rmin,alpha); % need to double check regularizatino here
    dr = dlmax(u(1:nspecies)-rmin,alpha);

    drho_dx_i = -q(1:nspecies).*dr;
    drhou_dx  = -q(nspecies+1);
    drhov_dx  = -q(nspecies+2);

    drho_dy_i = -q(ncu+1:ncu+nspecies).*dr;
    drhou_dy  = -q(ncu+nspecies+1);
    drhov_dy  = -q(ncu+nspecies+2);

    drho_dx = sum(drho_dx_i);
    drho_dy = sum(drho_dy_i);
    % Simple derived working quantities
    rho = sum(rho_i);
    rho_inv = 1./rho;
    uv = rhou.*rho_inv;
    vv = rhov.*rho_inv;
    E = rhoE * rho_inv; %energy
    H = E + p*rho_inv; %enthalpy
    H = Hmin + lmax(H - Hmin, alpha);

    % Critical speed of Sound
    c_star = sqrt((2.*gam1.*H) ./ (gam+1)); %TODO: this is fine for 1 temp but not 2

    % Computing derivatives for the sensors
    du_dx = (drhou_dx - drho_dx*uv)*rho_inv;
    dv_dx = (drhov_dx - drho_dx*vv)*rho_inv;
    du_dy = (drhou_dy - drho_dy*uv)*rho_inv;
    dv_dy = (drhov_dy - drho_dy*vv)*rho_inv;

    div_v = (du_dx + dv_dy); %TODO: check signs. Actually this probably is important, we want to make sure it's applied in negative v. pos dilitation
                  %      pretty sure my signs are okay. There is something strange about the code I was given. Trhouly don't understand the signs 
    vort = (dv_dx - du_dy); %TODO: sign here is a little weird 
    vort = sqrt(vort.*vort);
    
    % limit  divergence and vorticity    
    sigm = mu(23);
    div_v = limiting(div_v,-sigm,sigm,alpha,-sigm);
    vort = limiting(vort,0.0,sigm,alpha,0.0);

    % % Dilatation Sensor sb
    DucrosRatio = div_v.*div_v ./ (div_v.*div_v + vort.*vort + 1.0e-16);
%     DucrosRatio=1;
    sb = - (hm./porder) .* (div_v./c_star) .* DucrosRatio;
    sb = limiting(sb,sbmin,sbmax,alpha,sb0);

    % Artificial Bulk viscosity
    avb = rho * (kb.*hm./(porder)) .* sqrt(uv.^2 + vv.^2 + c_star.^2) .* sb;

    dY_dx_i = (drho_dx_i * rho - rho_i * drho_dx) * rho_inv * rho_inv;
    dY_dy_i = (drho_dy_i * rho - rho_i * drho_dy) * rho_inv * rho_inv;

    sY = hm./porder .* sqrt((dY_dx_i).^2 + (dY_dy_i).^2); % divide by free stream Yi's
    for i = 1:5
        sY(i) = limiting(sY(i), sbmin, sbmax, alpha, sb0);
    end
    avY = rho * (kD.*hm./porder) .* sqrt(uv^2 + c_star^2) .* sY; 

    % Assign artificial viscosities
    avField(1) = avb;  %  bulk
    avField(2:6) = avY;
end