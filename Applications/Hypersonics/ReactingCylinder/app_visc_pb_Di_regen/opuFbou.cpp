template <typename T> void opuFbou1(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uhg, T *nlg, T *tau, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw, Mutation::Mixture *mix)
{
	double Ustate[6];
	int nspecies = 5;
	int ndim = 2;
	double rho_scale = uinf[0];
	double u_scale = uinf[1];
	double rhoe_scale = uinf[2];
    double mu_scale = uinf[4];
    double kappa_scale = uinf[5];
    double Uwork[5];
    double dTdU[6];
	double D_i[5];
    double h_i[5];

	for (int i = 0; i <ng; i++) {
		T param1 = param[0];
		T param2 = param[1];
		T param19 = param[18];
		T param20 = param[19];
		T param21 = param[20];
		T param22 = param[21];
		T uinf1 = uinf[0];
		T uinf2 = uinf[1];
		T uinf3 = uinf[2];
		T uinf4 = uinf[3];
		T uinf5 = uinf[4];
		T uinf6 = uinf[5];
		T uinf7 = uinf[6];
		T uinf8 = uinf[7];
		T uinf9 = uinf[8];
		T uinf10 = uinf[9];
		T uinf11 = uinf[10];
		T uinf12 = uinf[11];
		T uinf13 = uinf[12];
		T uinf14 = uinf[13];
		T uinf15 = uinf[14];
		T uinf16 = uinf[15];
		T uinf17 = uinf[16];
		T uinf18 = uinf[17];
		T uinf19 = uinf[18];
		T uinf20 = uinf[19];
		T tau1 = tau[0];
		T tau2 = tau[1];
		T tau3 = tau[2];
		T tau4 = tau[3];
		T tau5 = tau[4];
		T tau6 = tau[5];
		T tau7 = tau[6];
		T tau8 = tau[7];
		T udg1 = udg[0*ng+i];
		T udg2 = udg[1*ng+i];
		T udg3 = udg[2*ng+i];
		T udg4 = udg[3*ng+i];
		T udg5 = udg[4*ng+i];
		T udg6 = udg[5*ng+i];
		T udg7 = udg[6*ng+i];
		T udg8 = udg[7*ng+i];
		T udg9 = udg[8*ng+i];
		T udg10 = udg[9*ng+i];
		T udg11 = udg[10*ng+i];
		T udg12 = udg[11*ng+i];
		T udg13 = udg[12*ng+i];
		T udg14 = udg[13*ng+i];
		T udg15 = udg[14*ng+i];
		T udg16 = udg[15*ng+i];
		T udg17 = udg[16*ng+i];
		T udg18 = udg[17*ng+i];
		T udg19 = udg[18*ng+i];
		T udg20 = udg[19*ng+i];
		T udg21 = udg[20*ng+i];
		T udg22 = udg[21*ng+i];
		T udg23 = udg[22*ng+i];
		T udg24 = udg[23*ng+i];
		T uhg1 = uhg[0*ng+i];
		T uhg2 = uhg[1*ng+i];
		T uhg3 = uhg[2*ng+i];
		T uhg4 = uhg[3*ng+i];
		T uhg5 = uhg[4*ng+i];
		T uhg6 = uhg[5*ng+i];
		T uhg7 = uhg[6*ng+i];
		T uhg8 = uhg[7*ng+i];
		T odg1 = odg[0*ng+i];
		T odg2 = odg[1*ng+i];
		T odg3 = odg[2*ng+i];
		T odg4 = odg[3*ng+i];
		T odg5 = odg[4*ng+i];
		T odg6 = odg[5*ng+i];
		T nlg1 = nlg[0*ng+i];
		T nlg2 = nlg[1*ng+i];

		T t1pi = 1.0/3.141592653589793;
        
        udg1 = udg1*(t1pi*atan(udg1*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg2 = udg2*(t1pi*atan(udg2*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg3 = udg3*(t1pi*atan(udg3*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg4 = udg4*(t1pi*atan(udg4*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg5 = udg5*(t1pi*atan(udg5*1.0E+12)+1.0/2.0)+3.182454300088011E-13;

		double Ucons[8] = {udg1, udg2, udg3, udg4, udg5, udg6, udg7, udg8};
		dimensionalizeConsVars(Ucons, (double*)uinf, nspecies, ndim);
		conservativeToState(Ucons, Ustate, (double*)uinf, nspecies, ndim);
		double rhovec[5] = {Ustate[0],Ustate[1],Ustate[2],Ustate[3],Ustate[4]};
		double rhoe = Ustate[nspecies];

        mix->setState(rhovec, &rhoe, 0);

		mix->averageDiffusionCoeffs(D_i);
        nondimensionalize_diffusionCoeffs(D_i, (double*)uinf, nspecies, ndim);
        mix->speciesHOverRT(h_i);
        nondimensionalize_enthalpies(h_i, (double*)uinf, nspecies, ndim);

        uinf1 = mix->P() / rhoe_scale;

        //D_i
        uinf2  = D_i[0]; uinf3  = D_i[1]; uinf4  = D_i[2]; uinf5  = D_i[3]; uinf6  = D_i[4]; 

        //h_i
		uinf7  = h_i[0]; uinf8  = h_i[1]; uinf9  = h_i[2]; uinf10 = h_i[3]; uinf11 = h_i[4]; //  h_5 

		uinf20 = 1.0/0.9;
		uinf12 = mix->viscosity() / mu_scale;
		uinf13 = mix->frozenThermalConductivity() / kappa_scale; //  kappa

        dT_dUstate(dTdU, Ustate, Uwork, nspecies, ndim, mix);
        nondimensionalize_dT_dUstate(dTdU, (double*)uinf, nspecies, nd);
		uinf14 = dTdU[0]; uinf15 = dTdU[1]; uinf16 = dTdU[2]; uinf17 = dTdU[3]; uinf18 = dTdU[4]; uinf19 = dTdU[5];

		T t2 = atan(param22);
		T t3 = odg2+uinf2;
		T t4 = odg3+uinf3;
		T t5 = odg4+uinf4;
		T t6 = odg5+uinf5;
		T t7 = odg6+uinf6;
		T t8 = param22*udg1;
		T t9 = param22*udg2;
		T t10 = param22*udg3;
		T t11 = param22*udg4;
		T t12 = param22*udg5;
		T t13 = param22*param22;
		T t14 = udg1*udg1;
		T t15 = udg2*udg2;
		T t16 = udg3*udg3;
		T t17 = udg4*udg4;
		T t18 = udg5*udg5;
		T t19 = udg6*udg6;
		T t20 = udg7*udg7;
		T t26 = 1.0/3.141592653589793;
		T t27 = odg1*param21*uinf20;
		T t28 = 1.0/param19;
		T t29 = 1.0/param20;
		T t21 = atan(t8);
		T t22 = atan(t9);
		T t23 = atan(t10);
		T t24 = atan(t11);
		T t25 = atan(t12);
		T t30 = t8*t8;
		T t31 = t9*t9;
		T t32 = t10*t10;
		T t33 = t11*t11;
		T t34 = t12*t12;
		T t35 = t2*t26;
		T t49 = t28*t29*uinf13;
		T t36 = t35*5.0;
		T t37 = t30+1.0;
		T t38 = t31+1.0;
		T t39 = t32+1.0;
		T t40 = t33+1.0;
		T t41 = t34+1.0;
		T t42 = t21*t26;
		T t43 = t22*t26;
		T t44 = t23*t26;
		T t45 = t24*t26;
		T t46 = t25*t26;
		T t47 = -t35;
		T t60 = t27+t49;
		T t48 = -t36;
		T t50 = 1.0/t37;
		T t51 = 1.0/t38;
		T t52 = 1.0/t39;
		T t53 = 1.0/t40;
		T t54 = 1.0/t41;
		T t55 = t42+1.0/2.0;
		T t56 = t43+1.0/2.0;
		T t57 = t44+1.0/2.0;
		T t58 = t45+1.0/2.0;
		T t59 = t46+1.0/2.0;
		T t61 = t55*udg1;
		T t62 = t56*udg2;
		T t63 = t57*udg3;
		T t64 = t58*udg4;
		T t65 = t59*udg5;
		T t66 = t8*t26*t50;
		T t67 = t9*t26*t51;
		T t68 = t10*t26*t52;
		T t69 = t11*t26*t53;
		T t70 = t12*t26*t54;
		T t71 = t47+t61+1.0/2.0;
		T t72 = t47+t62+1.0/2.0;
		T t73 = t47+t63+1.0/2.0;
		T t74 = t47+t64+1.0/2.0;
		T t75 = t47+t65+1.0/2.0;
		T t76 = t55+t66;
		T t77 = t56+t67;
		T t78 = t57+t68;
		T t79 = t58+t69;
		T t80 = t59+t70;
		T t91 = t48+t61+t62+t63+t64+t65+5.0/2.0;
		T t81 = t76*udg9;
		T t82 = t77*udg10;
		T t83 = t78*udg11;
		T t84 = t76*udg17;
		T t85 = t79*udg12;
		T t86 = t77*udg18;
		T t87 = t80*udg13;
		T t88 = t78*udg19;
		T t89 = t79*udg20;
		T t90 = t80*udg21;
		T t92 = 1.0/t91;
		T t93 = t92*t92;
		T t94 = t92*udg8;
		T t95 = t92*uinf1;
		T t96 = t92*udg6*udg7;
		T t99 = t81*t91;
		T t100 = t82*t91;
		T t101 = t83*t91;
		T t102 = t84*t91;
		T t103 = t85*t91;
		T t104 = t86*t91;
		T t105 = t87*t91;
		T t106 = t88*t91;
		T t107 = t89*t91;
		T t108 = t90*t91;
		T t119 = t81+t82+t83+t85+t87;
		T t120 = t84+t86+t88+t89+t90;
		T t97 = (t19*t93)/2.0;
		T t98 = (t20*t93)/2.0;
		T t109 = -t99;
		T t110 = -t100;
		T t111 = -t101;
		T t112 = -t102;
		T t113 = -t103;
		T t114 = -t104;
		T t115 = -t105;
		T t116 = -t106;
		T t117 = -t107;
		T t118 = -t108;
		T t121 = t94+t95;
		T t123 = t71*t119;
		T t124 = t72*t119;
		T t125 = t73*t119;
		T t126 = t74*t119;
		T t127 = t75*t119;
		T t128 = t71*t120;
		T t129 = t72*t120;
		T t130 = t73*t120;
		T t131 = t74*t120;
		T t132 = t75*t120;
		T t133 = t92*t119*udg6;
		T t134 = t92*t119*udg7;
		T t135 = t92*t120*udg6;
		T t136 = t92*t120*udg7;
		T t122 = t97+t98;
		T t137 = -t133;
		T t138 = -t134;
		T t139 = -t135;
		T t140 = -t136;
		T t145 = t109+t123;
		T t146 = t110+t124;
		T t147 = t111+t125;
		T t148 = t113+t126;
		T t149 = t115+t127;
		T t150 = t112+t128;
		T t151 = t114+t129;
		T t152 = t116+t130;
		T t153 = t117+t131;
		T t154 = t118+t132;
		T t155 = -t92*(t133-udg14);
		T t156 = -t92*(t134-udg15);
		T t157 = -t92*(t135-udg22);
		T t158 = -t92*(t136-udg23);
		T t159 = t92*(t133-udg14)*-2.0;
		T t160 = t92*(t136-udg23)*-2.0;
		T t161 = t92*(t136-udg23);
		T t163 = -t3*t92*(t99-t123);
		T t164 = -t3*t93*(t99-t123);
		T t165 = -t4*t92*(t100-t124);
		T t166 = -t4*t93*(t100-t124);
		T t167 = -t5*t92*(t101-t125);
		T t168 = -t5*t93*(t101-t125);
		T t169 = -t6*t92*(t103-t126);
		T t170 = -t6*t93*(t103-t126);
		T t171 = -t7*t92*(t105-t127);
		T t172 = -t7*t93*(t105-t127);
		T t173 = -t3*t92*(t102-t128);
		T t174 = -t3*t93*(t102-t128);
		T t175 = -t4*t92*(t104-t129);
		T t176 = -t4*t93*(t104-t129);
		T t177 = -t5*t92*(t106-t130);
		T t178 = -t5*t93*(t106-t130);
		T t179 = -t6*t92*(t107-t131);
		T t180 = -t6*t93*(t107-t131);
		T t181 = -t7*t92*(t108-t132);
		T t182 = -t7*t93*(t108-t132);
		T t183 = t3*t92*(t99-t123);
		T t184 = t4*t92*(t100-t124);
		T t185 = t5*t92*(t101-t125);
		T t186 = t6*t92*(t103-t126);
		T t187 = t7*t92*(t105-t127);
		T t188 = t3*t92*(t102-t128);
		T t189 = t4*t92*(t104-t129);
		T t190 = t5*t92*(t106-t130);
		T t191 = t6*t92*(t107-t131);
		T t192 = t7*t92*(t108-t132);
		T t198 = -t29*uinf12*(t92*(t134-udg15)+t92*(t135-udg22));
		T t205 = -t71*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127));
		T t206 = -t72*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127));
		T t207 = -t73*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127));
		T t208 = -t74*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127));
		T t209 = -t75*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127));
		T t210 = -t71*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132));
		T t211 = -t72*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132));
		T t212 = -t73*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132));
		T t213 = -t74*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132));
		T t214 = -t75*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132));
		T t141 = t137+udg14;
		T t142 = t138+udg15;
		T t143 = t139+udg22;
		T t144 = t140+udg23;
		T t162 = t161*2.0;
		T t193 = t155+t158;
		T t194 = t156+t157;
		T t195 = -odg1*(t161+t92*(t133-udg14));
		T t197 = t159+t161;
		T t199 = t29*uinf12*(t160+t92*(t133-udg14))*(-2.0/3.0);
		T t200 = t29*uinf12*(t160+t92*(t133-udg14))*(2.0/3.0);
		T t201 = t29*uinf12*(t158+t92*(t133-udg14)*2.0)*(-2.0/3.0);
		T t202 = t96+t198;
		T t203 = t164+t166+t168+t170+t172;
		T t204 = t174+t176+t178+t180+t182;
		T t196 = t155+t162;
		f[0*ng+i] = tau1*(udg1-uhg1)+nlg1*(t183+t205+t71*t92*udg6)+nlg2*(t188+t210+t71*t92*udg7);
		f[1*ng+i] = tau2*(udg2-uhg2)+nlg1*(t184+t206+t72*t92*udg6)+nlg2*(t189+t211+t72*t92*udg7);
		f[2*ng+i] = tau3*(udg3-uhg3)+nlg1*(t185+t207+t73*t92*udg6)+nlg2*(t190+t212+t73*t92*udg7);
		f[3*ng+i] = tau4*(udg4-uhg4)+nlg1*(t186+t208+t74*t92*udg6)+nlg2*(t191+t213+t74*t92*udg7);
		f[4*ng+i] = tau5*(udg5-uhg5)+nlg1*(t187+t209+t75*t92*udg6)+nlg2*(t192+t214+t75*t92*udg7);
		f[5*ng+i] = nlg2*t202+tau6*(udg6-uhg6)+nlg1*(t195+t201+uinf1+t19*t92);
		f[6*ng+i] = nlg1*t202+tau7*(udg7-uhg7)+nlg2*(t195+t200+uinf1+t20*t92);
		f[7*ng+i] = -nlg2*(-t121*udg7+uinf7*(t173+t71*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132)))+uinf8*(t175+t72*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132)))+uinf9*(t177+t73*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132)))+uinf10*(t179+t74*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132)))+uinf11*(t181+t75*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132)))-t60*(uinf19*(udg24+t91*(t93*udg6*(t135-udg22)+t93*udg7*(t136-udg23))-t120*t122)+t84*uinf14+t86*uinf15+t88*uinf16+t89*uinf17+t90*uinf18)+t92*udg7*(t199+odg1*(t161+t92*(t133-udg14)))+t29*t92*udg6*uinf12*(t92*(t134-udg15)+t92*(t135-udg22)))+tau8*(udg8-uhg8)-nlg1*(-t121*udg6+uinf7*(t163+t71*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127)))+uinf8*(t165+t72*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127)))+uinf9*(t167+t73*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127)))+uinf10*(t169+t74*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127)))+uinf11*(t171+t75*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127)))-t60*(uinf19*(udg16+t91*(t93*udg6*(t133-udg14)+t93*udg7*(t134-udg15))-t119*t122)+t81*uinf14+t82*uinf15+t83*uinf16+t85*uinf17+t87*uinf18)+t92*udg6*(odg1*(t161+t92*(t133-udg14))+t29*uinf12*(t158+t92*(t133-udg14)*2.0)*(2.0/3.0))+t29*t92*udg7*uinf12*(t92*(t134-udg15)+t92*(t135-udg22)));
	}
}

template <typename T> void opuFbou2(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uhg, T *nlg, T *tau, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw, Mutation::Mixture *mix)
{
	double Ustate[6];
	int nspecies = 5;
	int ndim = 2;
	double rho_scale = uinf[0];
	double u_scale = uinf[1];
	double rhoe_scale = uinf[2];
	double omega_scale = rho_scale*u_scale;
    double mu_scale = uinf[4];
    double kappa_scale = uinf[5];
    double Uwork[5];
    double dTdU[6];
	double D_i[5];
    double h_i[5];

	for (int i = 0; i <ng; i++) {
		T param1 = param[0];
		T param2 = param[1];
		T param19 = param[18];
		T param20 = param[19];
		T param21 = param[20];
		T param22 = param[21];
		T uinf1 = uinf[0];
		T uinf2 = uinf[1];
		T uinf3 = uinf[2];
		T uinf4 = uinf[3];
		T uinf5 = uinf[4];
		T uinf6 = uinf[5];
		T uinf7 = uinf[6];
		T uinf8 = uinf[7];
		T uinf9 = uinf[8];
		T uinf10 = uinf[9];
		T uinf11 = uinf[10];
		T uinf12 = uinf[11];
		T uinf13 = uinf[12];
		T uinf14 = uinf[13];
		T uinf15 = uinf[14];
		T uinf16 = uinf[15];
		T uinf17 = uinf[16];
		T uinf18 = uinf[17];
		T uinf19 = uinf[18];
		T uinf20 = uinf[19];
		T tau1 = tau[0];
		T tau2 = tau[1];
		T tau3 = tau[2];
		T tau4 = tau[3];
		T tau5 = tau[4];
		T tau6 = tau[5];
		T tau7 = tau[6];
		T tau8 = tau[7];
		T udg1 = udg[0*ng+i];
		T udg2 = udg[1*ng+i];
		T udg3 = udg[2*ng+i];
		T udg4 = udg[3*ng+i];
		T udg5 = udg[4*ng+i];
		T udg6 = udg[5*ng+i];
		T udg7 = udg[6*ng+i];
		T udg8 = udg[7*ng+i];
		T udg9 = udg[8*ng+i];
		T udg10 = udg[9*ng+i];
		T udg11 = udg[10*ng+i];
		T udg12 = udg[11*ng+i];
		T udg13 = udg[12*ng+i];
		T udg14 = udg[13*ng+i];
		T udg15 = udg[14*ng+i];
		T udg16 = udg[15*ng+i];
		T udg17 = udg[16*ng+i];
		T udg18 = udg[17*ng+i];
		T udg19 = udg[18*ng+i];
		T udg20 = udg[19*ng+i];
		T udg21 = udg[20*ng+i];
		T udg22 = udg[21*ng+i];
		T udg23 = udg[22*ng+i];
		T udg24 = udg[23*ng+i];
		T uhg1 = uhg[0*ng+i];
		T uhg2 = uhg[1*ng+i];
		T uhg3 = uhg[2*ng+i];
		T uhg4 = uhg[3*ng+i];
		T uhg5 = uhg[4*ng+i];
		T uhg6 = uhg[5*ng+i];
		T uhg7 = uhg[6*ng+i];
		T uhg8 = uhg[7*ng+i];
		T odg1 = odg[0*ng+i];
		T odg2 = odg[1*ng+i];
		T odg3 = odg[2*ng+i];
		T odg4 = odg[3*ng+i];
		T odg5 = odg[4*ng+i];
		T odg6 = odg[5*ng+i];
		T nlg1 = nlg[0*ng+i];
		T nlg2 = nlg[1*ng+i];

		T t1pi = 1.0/3.141592653589793;
        
        udg1 = udg1*(t1pi*atan(udg1*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg2 = udg2*(t1pi*atan(udg2*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg3 = udg3*(t1pi*atan(udg3*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg4 = udg4*(t1pi*atan(udg4*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg5 = udg5*(t1pi*atan(udg5*1.0E+12)+1.0/2.0)+3.182454300088011E-13;

		double Ucons[8] = {udg1, udg2, udg3, udg4, udg5, udg6, udg7, udg8};
		dimensionalizeConsVars(Ucons, (double*)uinf, nspecies, ndim);
		conservativeToState(Ucons, Ustate, (double*)uinf, nspecies, ndim);
		double rhovec[5] = {Ustate[0],Ustate[1],Ustate[2],Ustate[3],Ustate[4]};
		double rhoe = Ustate[nspecies];

        mix->setState(rhovec, &rhoe, 0);

		mix->averageDiffusionCoeffs(D_i);
        nondimensionalize_diffusionCoeffs(D_i, (double*)uinf, nspecies, ndim);
        mix->speciesHOverRT(h_i);
        nondimensionalize_enthalpies(h_i, (double*)uinf, nspecies, ndim);

        uinf1 = mix->P() / rhoe_scale;

        //D_i
        uinf2  = D_i[0]; uinf3  = D_i[1]; uinf4  = D_i[2]; uinf5  = D_i[3]; uinf6  = D_i[4]; 

        //h_i
		uinf7  = h_i[0]; uinf8  = h_i[1]; uinf9  = h_i[2]; uinf10 = h_i[3]; uinf11 = h_i[4]; //  h_5 

		uinf20 = 1.0/0.9;
		uinf12 = mix->viscosity() / mu_scale;
		uinf13 = mix->frozenThermalConductivity() / kappa_scale; //  kappa

        dT_dUstate(dTdU, Ustate, Uwork, nspecies, ndim, mix);
        nondimensionalize_dT_dUstate(dTdU, (double*)uinf, nspecies, nd);
		uinf14 = dTdU[0]; uinf15 = dTdU[1]; uinf16 = dTdU[2]; uinf17 = dTdU[3]; uinf18 = dTdU[4]; uinf19 = dTdU[5];

		T t2 = atan(param22);
		T t3 = odg2+uinf2;
		T t4 = odg3+uinf3;
		T t5 = odg4+uinf4;
		T t6 = odg5+uinf5;
		T t7 = odg6+uinf6;
		T t8 = param22*udg1;
		T t9 = param22*udg2;
		T t10 = param22*udg3;
		T t11 = param22*udg4;
		T t12 = param22*udg5;
		T t13 = param22*param22;
		T t14 = udg1*udg1;
		T t15 = udg2*udg2;
		T t16 = udg3*udg3;
		T t17 = udg4*udg4;
		T t18 = udg5*udg5;
		T t19 = udg6*udg6;
		T t20 = udg7*udg7;
		T t26 = 1.0/3.141592653589793;
		T t27 = odg1*param21*uinf20;
		T t28 = 1.0/param19;
		T t29 = 1.0/param20;
		T t21 = atan(t8);
		T t22 = atan(t9);
		T t23 = atan(t10);
		T t24 = atan(t11);
		T t25 = atan(t12);
		T t30 = t8*t8;
		T t31 = t9*t9;
		T t32 = t10*t10;
		T t33 = t11*t11;
		T t34 = t12*t12;
		T t35 = t2*t26;
		T t49 = t28*t29*uinf13;
		T t36 = t35*5.0;
		T t37 = t30+1.0;
		T t38 = t31+1.0;
		T t39 = t32+1.0;
		T t40 = t33+1.0;
		T t41 = t34+1.0;
		T t42 = t21*t26;
		T t43 = t22*t26;
		T t44 = t23*t26;
		T t45 = t24*t26;
		T t46 = t25*t26;
		T t47 = -t35;
		T t60 = t27+t49;
		T t48 = -t36;
		T t50 = 1.0/t37;
		T t51 = 1.0/t38;
		T t52 = 1.0/t39;
		T t53 = 1.0/t40;
		T t54 = 1.0/t41;
		T t55 = t42+1.0/2.0;
		T t56 = t43+1.0/2.0;
		T t57 = t44+1.0/2.0;
		T t58 = t45+1.0/2.0;
		T t59 = t46+1.0/2.0;
		T t61 = t55*udg1;
		T t62 = t56*udg2;
		T t63 = t57*udg3;
		T t64 = t58*udg4;
		T t65 = t59*udg5;
		T t66 = t8*t26*t50;
		T t67 = t9*t26*t51;
		T t68 = t10*t26*t52;
		T t69 = t11*t26*t53;
		T t70 = t12*t26*t54;
		T t71 = t47+t61+1.0/2.0;
		T t72 = t47+t62+1.0/2.0;
		T t73 = t47+t63+1.0/2.0;
		T t74 = t47+t64+1.0/2.0;
		T t75 = t47+t65+1.0/2.0;
		T t76 = t55+t66;
		T t77 = t56+t67;
		T t78 = t57+t68;
		T t79 = t58+t69;
		T t80 = t59+t70;
		T t91 = t48+t61+t62+t63+t64+t65+5.0/2.0;
		T t81 = t76*udg9;
		T t82 = t77*udg10;
		T t83 = t78*udg11;
		T t84 = t76*udg17;
		T t85 = t79*udg12;
		T t86 = t77*udg18;
		T t87 = t80*udg13;
		T t88 = t78*udg19;
		T t89 = t79*udg20;
		T t90 = t80*udg21;
		T t92 = 1.0/t91;
		T t93 = t92*t92;
		T t94 = t92*udg8;
		T t95 = t92*uinf1;
		T t96 = t92*udg6*udg7;
		T t99 = t81*t91;
		T t100 = t82*t91;
		T t101 = t83*t91;
		T t102 = t84*t91;
		T t103 = t85*t91;
		T t104 = t86*t91;
		T t105 = t87*t91;
		T t106 = t88*t91;
		T t107 = t89*t91;
		T t108 = t90*t91;
		T t119 = t81+t82+t83+t85+t87;
		T t120 = t84+t86+t88+t89+t90;
		T t97 = (t19*t93)/2.0;
		T t98 = (t20*t93)/2.0;
		T t109 = -t99;
		T t110 = -t100;
		T t111 = -t101;
		T t112 = -t102;
		T t113 = -t103;
		T t114 = -t104;
		T t115 = -t105;
		T t116 = -t106;
		T t117 = -t107;
		T t118 = -t108;
		T t121 = t94+t95;
		T t123 = t71*t119;
		T t124 = t72*t119;
		T t125 = t73*t119;
		T t126 = t74*t119;
		T t127 = t75*t119;
		T t128 = t71*t120;
		T t129 = t72*t120;
		T t130 = t73*t120;
		T t131 = t74*t120;
		T t132 = t75*t120;
		T t133 = t92*t119*udg6;
		T t134 = t92*t119*udg7;
		T t135 = t92*t120*udg6;
		T t136 = t92*t120*udg7;
		T t122 = t97+t98;
		T t137 = -t133;
		T t138 = -t134;
		T t139 = -t135;
		T t140 = -t136;
		T t145 = t109+t123;
		T t146 = t110+t124;
		T t147 = t111+t125;
		T t148 = t113+t126;
		T t149 = t115+t127;
		T t150 = t112+t128;
		T t151 = t114+t129;
		T t152 = t116+t130;
		T t153 = t117+t131;
		T t154 = t118+t132;
		T t155 = -t92*(t133-udg14);
		T t156 = -t92*(t134-udg15);
		T t157 = -t92*(t135-udg22);
		T t158 = -t92*(t136-udg23);
		T t159 = t92*(t133-udg14)*-2.0;
		T t160 = t92*(t136-udg23)*-2.0;
		T t161 = t92*(t136-udg23);
		T t163 = -t3*t92*(t99-t123);
		T t164 = -t3*t93*(t99-t123);
		T t165 = -t4*t92*(t100-t124);
		T t166 = -t4*t93*(t100-t124);
		T t167 = -t5*t92*(t101-t125);
		T t168 = -t5*t93*(t101-t125);
		T t169 = -t6*t92*(t103-t126);
		T t170 = -t6*t93*(t103-t126);
		T t171 = -t7*t92*(t105-t127);
		T t172 = -t7*t93*(t105-t127);
		T t173 = -t3*t92*(t102-t128);
		T t174 = -t3*t93*(t102-t128);
		T t175 = -t4*t92*(t104-t129);
		T t176 = -t4*t93*(t104-t129);
		T t177 = -t5*t92*(t106-t130);
		T t178 = -t5*t93*(t106-t130);
		T t179 = -t6*t92*(t107-t131);
		T t180 = -t6*t93*(t107-t131);
		T t181 = -t7*t92*(t108-t132);
		T t182 = -t7*t93*(t108-t132);
		T t183 = t3*t92*(t99-t123);
		T t184 = t4*t92*(t100-t124);
		T t185 = t5*t92*(t101-t125);
		T t186 = t6*t92*(t103-t126);
		T t187 = t7*t92*(t105-t127);
		T t188 = t3*t92*(t102-t128);
		T t189 = t4*t92*(t104-t129);
		T t190 = t5*t92*(t106-t130);
		T t191 = t6*t92*(t107-t131);
		T t192 = t7*t92*(t108-t132);
		T t198 = -t29*uinf12*(t92*(t134-udg15)+t92*(t135-udg22));
		T t205 = -t71*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127));
		T t206 = -t72*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127));
		T t207 = -t73*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127));
		T t208 = -t74*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127));
		T t209 = -t75*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127));
		T t210 = -t71*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132));
		T t211 = -t72*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132));
		T t212 = -t73*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132));
		T t213 = -t74*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132));
		T t214 = -t75*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132));
		T t141 = t137+udg14;
		T t142 = t138+udg15;
		T t143 = t139+udg22;
		T t144 = t140+udg23;
		T t162 = t161*2.0;
		T t193 = t155+t158;
		T t194 = t156+t157;
		T t195 = -odg1*(t161+t92*(t133-udg14));
		T t197 = t159+t161;
		T t199 = t29*uinf12*(t160+t92*(t133-udg14))*(-2.0/3.0);
		T t200 = t29*uinf12*(t160+t92*(t133-udg14))*(2.0/3.0);
		T t201 = t29*uinf12*(t158+t92*(t133-udg14)*2.0)*(-2.0/3.0);
		T t202 = t96+t198;
		T t203 = t164+t166+t168+t170+t172;
		T t204 = t174+t176+t178+t180+t182;
		T t196 = t155+t162;
		f[0*ng+i] = tau1*(udg1-uhg1)+nlg1*(t183+t205+t71*t92*udg6)+nlg2*(t188+t210+t71*t92*udg7);
		f[1*ng+i] = tau2*(udg2-uhg2)+nlg1*(t184+t206+t72*t92*udg6)+nlg2*(t189+t211+t72*t92*udg7);
		f[2*ng+i] = tau3*(udg3-uhg3)+nlg1*(t185+t207+t73*t92*udg6)+nlg2*(t190+t212+t73*t92*udg7);
		f[3*ng+i] = tau4*(udg4-uhg4)+nlg1*(t186+t208+t74*t92*udg6)+nlg2*(t191+t213+t74*t92*udg7);
		f[4*ng+i] = tau5*(udg5-uhg5)+nlg1*(t187+t209+t75*t92*udg6)+nlg2*(t192+t214+t75*t92*udg7);
		f[5*ng+i] = nlg2*t202+tau6*(udg6-uhg6)+nlg1*(t195+t201+uinf1+t19*t92);
		f[6*ng+i] = nlg1*t202+tau7*(udg7-uhg7)+nlg2*(t195+t200+uinf1+t20*t92);
		f[7*ng+i] = -nlg2*(-t121*udg7+uinf7*(t173+t71*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132)))+uinf8*(t175+t72*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132)))+uinf9*(t177+t73*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132)))+uinf10*(t179+t74*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132)))+uinf11*(t181+t75*(t3*t93*(t102-t128)+t4*t93*(t104-t129)+t5*t93*(t106-t130)+t6*t93*(t107-t131)+t7*t93*(t108-t132)))-t60*(uinf19*(udg24+t91*(t93*udg6*(t135-udg22)+t93*udg7*(t136-udg23))-t120*t122)+t84*uinf14+t86*uinf15+t88*uinf16+t89*uinf17+t90*uinf18)+t92*udg7*(t199+odg1*(t161+t92*(t133-udg14)))+t29*t92*udg6*uinf12*(t92*(t134-udg15)+t92*(t135-udg22)))+tau8*(udg8-uhg8)-nlg1*(-t121*udg6+uinf7*(t163+t71*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127)))+uinf8*(t165+t72*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127)))+uinf9*(t167+t73*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127)))+uinf10*(t169+t74*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127)))+uinf11*(t171+t75*(t3*t93*(t99-t123)+t4*t93*(t100-t124)+t5*t93*(t101-t125)+t6*t93*(t103-t126)+t7*t93*(t105-t127)))-t60*(uinf19*(udg16+t91*(t93*udg6*(t133-udg14)+t93*udg7*(t134-udg15))-t119*t122)+t81*uinf14+t82*uinf15+t83*uinf16+t85*uinf17+t87*uinf18)+t92*udg6*(odg1*(t161+t92*(t133-udg14))+t29*uinf12*(t158+t92*(t133-udg14)*2.0)*(2.0/3.0))+t29*t92*udg7*uinf12*(t92*(t134-udg15)+t92*(t135-udg22)));
	}
}

template <typename T> void opuFbou3(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uhg, T *nlg, T *tau, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw, Mutation::Mixture *mix)
{
	double Ustate[6];
	int nspecies = 5;
	int ndim = 2;
	double rho_scale = uinf[0];
	double u_scale = uinf[1];
	double rhoe_scale = uinf[2];
	double omega_scale = rho_scale*u_scale;
    double mu_scale = uinf[4];
    double kappa_scale = uinf[5];
    double Uwork[5];
    double dTdU[6];
	double D_i[5];
    double h_i[5];

	for (int i = 0; i <ng; i++) {
		T param2 = param[1];
		T param20 = param[19];
		T param22 = param[21];
		T uinf1 = uinf[0];
		T uinf12 = uinf[11];
		T tau6 = tau[5];
		T tau7 = tau[6];
		T udg1 = udg[0*ng+i];
		T udg2 = udg[1*ng+i];
		T udg3 = udg[2*ng+i];
		T udg4 = udg[3*ng+i];
		T udg5 = udg[4*ng+i];
		T udg6 = udg[5*ng+i];
		T udg7 = udg[6*ng+i];
		T udg8 = udg[7*ng+i];
		T udg9 = udg[8*ng+i];
		T udg10 = udg[9*ng+i];
		T udg11 = udg[10*ng+i];
		T udg12 = udg[11*ng+i];
		T udg13 = udg[12*ng+i];
		T udg14 = udg[13*ng+i];
		T udg15 = udg[14*ng+i];
		T udg17 = udg[16*ng+i];
		T udg18 = udg[17*ng+i];
		T udg19 = udg[18*ng+i];
		T udg20 = udg[19*ng+i];
		T udg21 = udg[20*ng+i];
		T udg22 = udg[21*ng+i];
		T udg23 = udg[22*ng+i];
		T uhg6 = uhg[5*ng+i];
		T uhg7 = uhg[6*ng+i];
		T odg1 = odg[0*ng+i];
		T nlg1 = nlg[0*ng+i];
		T nlg2 = nlg[1*ng+i];

		T t1pi = 1.0/3.141592653589793;
        
        udg1 = udg1*(t1pi*atan(udg1*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg2 = udg2*(t1pi*atan(udg2*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg3 = udg3*(t1pi*atan(udg3*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg4 = udg4*(t1pi*atan(udg4*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg5 = udg5*(t1pi*atan(udg5*1.0E+12)+1.0/2.0)+3.182454300088011E-13;

		double Ucons[8] = {udg1, udg2, udg3, udg4, udg5, udg6, udg7, udg8};
		dimensionalizeConsVars(Ucons, (double*)uinf, nspecies, ndim);
		conservativeToState(Ucons, Ustate, (double*)uinf, nspecies, ndim);
		double rhovec[5] = {Ustate[0],Ustate[1],Ustate[2],Ustate[3],Ustate[4]};
		double rhoe = Ustate[nspecies];

        mix->setState(rhovec, &rhoe, 0);
		
        uinf1 = mix->P() / rhoe_scale;

		uinf12 = mix->viscosity() / mu_scale;

		T t2 = atan(param22);
		T t3 = param22*udg1;
		T t4 = param22*udg2;
		T t5 = param22*udg3;
		T t6 = param22*udg4;
		T t7 = param22*udg5;
		T t8 = param22*param22;
		T t9 = udg1*udg1;
		T t10 = udg2*udg2;
		T t11 = udg3*udg3;
		T t12 = udg4*udg4;
		T t13 = udg5*udg5;
		T t19 = 1.0/3.141592653589793;
		T t20 = 1.0/param20;
		T t14 = atan(t3);
		T t15 = atan(t4);
		T t16 = atan(t5);
		T t17 = atan(t6);
		T t18 = atan(t7);
		T t21 = t3*t3;
		T t22 = t4*t4;
		T t23 = t5*t5;
		T t24 = t6*t6;
		T t25 = t7*t7;
		T t26 = t2*t19*5.0;
		T t27 = t21+1.0;
		T t28 = t22+1.0;
		T t29 = t23+1.0;
		T t30 = t24+1.0;
		T t31 = t25+1.0;
		T t32 = t14*t19;
		T t33 = t15*t19;
		T t34 = t16*t19;
		T t35 = t17*t19;
		T t36 = t18*t19;
		T t37 = -t26;
		T t38 = 1.0/t27;
		T t39 = 1.0/t28;
		T t40 = 1.0/t29;
		T t41 = 1.0/t30;
		T t42 = 1.0/t31;
		T t43 = t32+1.0/2.0;
		T t44 = t33+1.0/2.0;
		T t45 = t34+1.0/2.0;
		T t46 = t35+1.0/2.0;
		T t47 = t36+1.0/2.0;
		T t48 = t43*udg1;
		T t49 = t44*udg2;
		T t50 = t45*udg3;
		T t51 = t46*udg4;
		T t52 = t47*udg5;
		T t53 = t3*t19*t38;
		T t54 = t4*t19*t39;
		T t55 = t5*t19*t40;
		T t56 = t6*t19*t41;
		T t57 = t7*t19*t42;
		T t58 = t43+t53;
		T t59 = t44+t54;
		T t60 = t45+t55;
		T t61 = t46+t56;
		T t62 = t47+t57;
		T t73 = t37+t48+t49+t50+t51+t52+5.0/2.0;
		T t63 = t58*udg9;
		T t64 = t59*udg10;
		T t65 = t60*udg11;
		T t66 = t58*udg17;
		T t67 = t61*udg12;
		T t68 = t59*udg18;
		T t69 = t62*udg13;
		T t70 = t60*udg19;
		T t71 = t61*udg20;
		T t72 = t62*udg21;
		T t74 = 1.0/t73;
		T t75 = t74*udg6*udg7;
		T t76 = t63+t64+t65+t67+t69;
		T t77 = t66+t68+t70+t71+t72;
		T t78 = t74*t76*udg6;
		T t79 = t74*t76*udg7;
		T t80 = t74*t77*udg6;
		T t81 = t74*t77*udg7;
		T t82 = -t78;
		T t83 = -t79;
		T t84 = -t80;
		T t85 = -t81;
		T t90 = -t74*(t78-udg14);
		T t91 = -t74*(t79-udg15);
		T t92 = -t74*(t80-udg22);
		T t93 = -t74*(t81-udg23);
		T t96 = -odg1*(t74*(t78-udg14)+t74*(t81-udg23));
		T t97 = -t20*uinf12*(t74*(t79-udg15)+t74*(t80-udg22));
		T t86 = t82+udg14;
		T t87 = t83+udg15;
		T t88 = t84+udg22;
		T t89 = t85+udg23;
		T t94 = t90+t93;
		T t95 = t91+t92;
		T t98 = t75+t97;
		f[0*ng+i] = 0.0;
		f[1*ng+i] = 0.0;
		f[2*ng+i] = 0.0;
		f[3*ng+i] = 0.0;
		f[4*ng+i] = 0.0;
		f[5*ng+i] = nlg2*t98+nlg1*(t96+uinf1+t74*(udg6*udg6)-t20*uinf12*(t93+t74*(t78-udg14)*2.0)*(2.0/3.0))+tau6*(udg6-uhg6);
		f[6*ng+i] = nlg1*t98+nlg2*(t96+uinf1+t74*(udg7*udg7)+t20*uinf12*(t74*(t78-udg14)-t74*(t81-udg23)*2.0)*(2.0/3.0))+tau7*(udg7-uhg7);
		f[7*ng+i] = 0.0;
	}
}

template <typename T> void opuFbou(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uhg, T *nlg, T *tau, T *uinf, T *param, T time, int modelnumber, int ib, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw, Mutation::Mixture *mix)
{
	if (ib == 1)
		opuFbou1(f, xdg, udg, odg, wdg, uhg, nlg, tau, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw, mix);
	else if (ib == 2)
		opuFbou2(f, xdg, udg, odg, wdg, uhg, nlg, tau, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw, mix);
	else if (ib == 3)
		opuFbou3(f, xdg, udg, odg, wdg, uhg, nlg, tau, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw, mix);
}

template void opuFbou(double *, double *, double *, double *, double *, double *, double *, double *, double *, double *, double, int, int, int, int, int, int, int, int, int, Mutation::Mixture *);
template void opuFbou(float *, float *, float *, float *, float *, float *, float *, float *, float *, float *, float, int, int, int, int, int, int, int, int, int, Mutation::Mixture *);
