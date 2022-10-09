template <typename T> void opuFbou1(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uhg, T *nlg, T *tau, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw, Mutation::Mixture *mix)
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


		uinf1  = mix->P()/rhoe_scale;
        uinf2  = 0.0; //  D_1
		uinf3  = 0.0; //  D_2
		uinf4  = 0.0; //  D_3 
		uinf5  = 0.0; //  D_4
		uinf6  = 0.0; //  D_5
		uinf7  = 0.0; //  h_1
		uinf8  = 0.0; //  h_2
		uinf9  = 0.0; //  h_3
		uinf10 = 0.0; //  h_4
		uinf11 = 0.0; //  h_5 
		uinf12 = 0.0; //  mu
		uinf13 = 0.0; //  kappa
		// uinf2  = D_i[0]; //  D_1
		// uinf3  = D_i[1]; //  D_2
		// uinf4  = D_i[2]; //  D_3 
		// uinf5  = D_i[3]; //  D_4
		// uinf6  = D_i[4]; //  D_5
		// uinf7  = h_i[0]; //  h_1
		// uinf8  = h_i[1]; //  h_2
		// uinf9  = h_i[2]; //  h_3
		// uinf10 = h_i[3]; //  h_4
		// uinf11 = h_i[4]; //  h_5 
		// uinf12 = mix->viscosity() / mu_scale; //  mu
		// uinf13 = mix->frozenThermalConductivity() / kappa_scale; //  kappa

        dT_dUstate(dTdU, Ustate, Uwork, nspecies, ndim, mix);
        nondimensionalize_dT_dUstate(dTdU, (double*)uinf, nspecies, nd);
		uinf14 = dTdU[0];
		uinf15 = dTdU[1];
		uinf16 = dTdU[2];
		uinf17 = dTdU[3];
		uinf18 = dTdU[4];
		uinf19 = dTdU[5];

		T t2 = udg1*udg1;
		T t3 = udg2*udg2;
		T t4 = udg3*udg3;
		T t5 = udg4*udg4;
		T t6 = udg5*udg5;
		T t7 = udg6*udg6;
		T t8 = udg7*udg7;
		T t9 = udg17*udg17;
		T t10 = udg18*udg18;
		T t11 = udg19*udg19;
		T t12 = udg20*udg20;
		T t13 = udg21*udg21;
		T t14 = 1.0/3.141592653589793;
		T t15 = 1.0/param19;
		T t16 = 1.0/param20;
		T t17 = udg1*1.0E+12;
		T t18 = udg2*1.0E+12;
		T t19 = udg3*1.0E+12;
		T t20 = udg4*1.0E+12;
		T t21 = udg5*1.0E+12;
		T t22 = udg17*1.0E+12;
		T t23 = udg18*1.0E+12;
		T t24 = udg19*1.0E+12;
		T t25 = udg20*1.0E+12;
		T t26 = udg21*1.0E+12;
		T t27 = atan(t17);
		T t28 = atan(t18);
		T t29 = atan(t19);
		T t30 = atan(t20);
		T t31 = atan(t21);
		T t32 = atan(t22);
		T t33 = atan(t23);
		T t34 = atan(t24);
		T t35 = atan(t25);
		T t36 = atan(t26);
		T t57 = t2*1.0E+24;
		T t58 = t3*1.0E+24;
		T t59 = t4*1.0E+24;
		T t60 = t5*1.0E+24;
		T t61 = t6*1.0E+24;
		T t62 = t9*1.0E+24;
		T t63 = t10*1.0E+24;
		T t64 = t11*1.0E+24;
		T t65 = t12*1.0E+24;
		T t66 = t13*1.0E+24;
		T t37 = t14*t27;
		T t38 = t14*t28;
		T t39 = t14*t29;
		T t40 = t14*t30;
		T t41 = t14*t31;
		T t42 = t14*t32;
		T t43 = t14*t33;
		T t44 = t14*t34;
		T t45 = t14*t35;
		T t46 = t14*t36;
		T t67 = t57+1.0;
		T t68 = t58+1.0;
		T t69 = t59+1.0;
		T t70 = t60+1.0;
		T t71 = t61+1.0;
		T t72 = t62+1.0;
		T t73 = t63+1.0;
		T t74 = t64+1.0;
		T t75 = t65+1.0;
		T t76 = t66+1.0;
		T t47 = t37+1.0/2.0;
		T t48 = t38+1.0/2.0;
		T t49 = t39+1.0/2.0;
		T t50 = t40+1.0/2.0;
		T t51 = t41+1.0/2.0;
		T t77 = 1.0/t67;
		T t78 = 1.0/t68;
		T t79 = 1.0/t69;
		T t80 = 1.0/t70;
		T t81 = 1.0/t71;
		T t82 = 1.0/t72;
		T t83 = 1.0/t73;
		T t84 = 1.0/t74;
		T t85 = 1.0/t75;
		T t86 = 1.0/t76;
		T t52 = t47*udg1;
		T t53 = t48*udg2;
		T t54 = t49*udg3;
		T t55 = t50*udg4;
		T t56 = t51*udg5;
		T t92 = t14*t17*t77;
		T t93 = t14*t18*t78;
		T t94 = t14*t19*t79;
		T t95 = t14*t20*t80;
		T t96 = t14*t21*t81;
		T t97 = t14*t22*t82;
		T t98 = t14*t23*t83;
		T t99 = t14*t24*t84;
		T t100 = t14*t25*t85;
		T t101 = t14*t26*t86;
		T t87 = t52+3.182454300088011E-13;
		T t88 = t53+3.182454300088011E-13;
		T t89 = t54+3.182454300088011E-13;
		T t90 = t55+3.182454300088011E-13;
		T t91 = t56+3.182454300088011E-13;
		T t102 = t47+t92;
		T t103 = t48+t93;
		T t104 = t49+t94;
		T t105 = t50+t95;
		T t106 = t51+t96;
		T t107 = t42+t97+1.0/2.0;
		T t108 = t43+t98+1.0/2.0;
		T t109 = t44+t99+1.0/2.0;
		T t110 = t45+t100+1.0/2.0;
		T t111 = t46+t101+1.0/2.0;
		T t122 = t52+t53+t54+t55+t56+1.591227150044006E-12;
		T t112 = t102*udg9;
		T t113 = t103*udg10;
		T t114 = t104*udg11;
		T t115 = t105*udg12;
		T t116 = t106*udg13;
		T t117 = t107*udg17;
		T t118 = t108*udg18;
		T t119 = t109*udg19;
		T t120 = t110*udg20;
		T t121 = t111*udg21;
		T t123 = 1.0/t122;
		T t124 = t123*t123;
		T t125 = t123*udg8;
		T t126 = t123*uinf1;
		T t127 = t123*udg6*udg7;
		T t130 = t112*t122;
		T t131 = t113*t122;
		T t132 = t114*t122;
		T t133 = t115*t122;
		T t134 = t116*t122;
		T t135 = t117*t122;
		T t136 = t118*t122;
		T t137 = t119*t122;
		T t138 = t120*t122;
		T t139 = t121*t122;
		T t152 = t112+t113+t114+t115+t116;
		T t153 = t117+t118+t119+t120+t121;
		T t128 = (t7*t124)/2.0;
		T t129 = (t8*t124)/2.0;
		T t140 = -t130;
		T t141 = -t131;
		T t142 = -t132;
		T t143 = -t133;
		T t144 = -t134;
		T t145 = -t135;
		T t146 = -t136;
		T t147 = -t137;
		T t148 = -t138;
		T t149 = -t139;
		T t150 = t125+t126;
		T t154 = t87*t152;
		T t155 = t88*t152;
		T t156 = t89*t152;
		T t157 = t90*t152;
		T t158 = t91*t152;
		T t159 = t87*t153;
		T t160 = t88*t153;
		T t161 = t89*t153;
		T t162 = t90*t153;
		T t163 = t91*t153;
		T t164 = t123*t152*udg6;
		T t165 = t123*t152*udg7;
		T t166 = t123*t153*udg6;
		T t167 = t123*t153*udg7;
		T t151 = t128+t129;
		T t168 = -t164;
		T t169 = -t165;
		T t170 = -t166;
		T t171 = -t167;
		T t176 = t140+t154;
		T t177 = t141+t155;
		T t178 = t142+t156;
		T t179 = t143+t157;
		T t180 = t144+t158;
		T t181 = t145+t159;
		T t182 = t146+t160;
		T t183 = t147+t161;
		T t184 = t148+t162;
		T t185 = t149+t163;
		T t186 = -t123*(t164-udg14);
		T t187 = -t123*(t165-udg15);
		T t188 = -t123*(t166-udg22);
		T t189 = -t123*(t167-udg23);
		T t190 = t123*(t164-udg14)*-2.0;
		T t191 = t123*(t167-udg23)*-2.0;
		T t192 = t123*(t167-udg23);
		T t194 = -t123*uinf2*(t130-t154);
		T t195 = -t124*uinf2*(t130-t154);
		T t196 = -t123*uinf3*(t131-t155);
		T t197 = -t124*uinf3*(t131-t155);
		T t198 = -t123*uinf4*(t132-t156);
		T t199 = -t124*uinf4*(t132-t156);
		T t200 = -t123*uinf5*(t133-t157);
		T t201 = -t124*uinf5*(t133-t157);
		T t202 = -t123*uinf6*(t134-t158);
		T t203 = -t124*uinf6*(t134-t158);
		T t204 = -t123*uinf2*(t135-t159);
		T t205 = -t124*uinf2*(t135-t159);
		T t206 = -t123*uinf3*(t136-t160);
		T t207 = -t124*uinf3*(t136-t160);
		T t208 = -t123*uinf4*(t137-t161);
		T t209 = -t124*uinf4*(t137-t161);
		T t210 = -t123*uinf5*(t138-t162);
		T t211 = -t124*uinf5*(t138-t162);
		T t212 = -t123*uinf6*(t139-t163);
		T t213 = -t124*uinf6*(t139-t163);
		T t214 = t123*uinf2*(t130-t154);
		T t215 = t123*uinf3*(t131-t155);
		T t216 = t123*uinf4*(t132-t156);
		T t217 = t123*uinf5*(t133-t157);
		T t218 = t123*uinf6*(t134-t158);
		T t219 = t123*uinf2*(t135-t159);
		T t220 = t123*uinf3*(t136-t160);
		T t221 = t123*uinf4*(t137-t161);
		T t222 = t123*uinf5*(t138-t162);
		T t223 = t123*uinf6*(t139-t163);
		T t227 = -t16*uinf12*(t123*(t165-udg15)+t123*(t166-udg22));
		T t230 = -t87*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158));
		T t231 = -t88*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158));
		T t232 = -t89*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158));
		T t233 = -t90*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158));
		T t234 = -t91*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158));
		T t235 = -t87*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163));
		T t236 = -t88*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163));
		T t237 = -t89*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163));
		T t238 = -t90*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163));
		T t239 = -t91*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163));
		T t172 = t168+udg14;
		T t173 = t169+udg15;
		T t174 = t170+udg22;
		T t175 = t171+udg23;
		T t193 = t192*2.0;
		T t224 = t187+t188;
		T t226 = t190+t192;
		T t228 = t195+t197+t199+t201+t203;
		T t229 = t205+t207+t209+t211+t213;
		f[0*ng+i] = nlg1*(t214+t230+odg1*t112+t87*t123*udg6)+nlg2*(t219+t235+odg1*t117+t87*t123*udg7)+tau1*(udg1-uhg1);
		f[1*ng+i] = nlg1*(t215+t231+odg1*t113+t88*t123*udg6)+nlg2*(t220+t236+odg1*t118+t88*t123*udg7)+tau2*(udg2-uhg2);
		f[2*ng+i] = nlg1*(t216+t232+odg1*t114+t89*t123*udg6)+nlg2*(t221+t237+odg1*t119+t89*t123*udg7)+tau3*(udg3-uhg3);
		f[3*ng+i] = nlg1*(t217+t233+odg1*t115+t90*t123*udg6)+nlg2*(t222+t238+odg1*t120+t90*t123*udg7)+tau4*(udg4-uhg4);
		f[4*ng+i] = nlg1*(t218+t234+odg1*t116+t91*t123*udg6)+nlg2*(t223+t239+odg1*t121+t91*t123*udg7)+tau5*(udg5-uhg5);
		f[5*ng+i] = nlg2*(t127+t227+odg1*udg22)+tau6*(udg6-uhg6)+nlg1*(uinf1+odg1*udg14+t7*t123-t16*uinf12*(t189+t123*(t164-udg14)*2.0)*(2.0/3.0));
		f[6*ng+i] = nlg1*(t127+t227+odg1*udg15)+tau7*(udg7-uhg7)+nlg2*(uinf1+odg1*udg23+t8*t123+t16*uinf12*(t191+t123*(t164-udg14))*(2.0/3.0));
		f[7*ng+i] = -nlg1*(-odg1*udg16-t150*udg6+uinf7*(t194+t87*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158)))+uinf8*(t196+t88*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158)))+uinf9*(t198+t89*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158)))+uinf10*(t200+t90*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158)))+uinf11*(t202+t91*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158)))-t15*t16*uinf13*(uinf19*(udg16+t122*(t124*udg6*(t164-udg14)+t124*udg7*(t165-udg15))-t151*t152)+t112*uinf14+t113*uinf15+t114*uinf16+t115*uinf17+t116*uinf18)+t16*t123*udg6*uinf12*(t189+t123*(t164-udg14)*2.0)*(2.0/3.0)+t16*t123*udg7*uinf12*(t123*(t165-udg15)+t123*(t166-udg22)))-nlg2*(-odg1*udg24-t150*udg7+uinf7*(t204+t87*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163)))+uinf8*(t206+t88*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163)))+uinf9*(t208+t89*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163)))+uinf10*(t210+t90*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163)))+uinf11*(t212+t91*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163)))-t15*t16*uinf13*(uinf19*(udg24+t122*(t124*udg6*(t166-udg22)+t124*udg7*(t167-udg23))-t151*t153)+t117*uinf14+t118*uinf15+t119*uinf16+t120*uinf17+t121*uinf18)-t16*t123*udg7*uinf12*(t191+t123*(t164-udg14))*(2.0/3.0)+t16*t123*udg6*uinf12*(t123*(t165-udg15)+t123*(t166-udg22)))+tau8*(udg8-uhg8);
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
        uinf2  = 0.0; //  D_1
		uinf3  = 0.0; //  D_2
		uinf4  = 0.0; //  D_3 
		uinf5  = 0.0; //  D_4
		uinf6  = 0.0; //  D_5
		uinf7  = 0.0; //  h_1
		uinf8  = 0.0; //  h_2
		uinf9  = 0.0; //  h_3
		uinf10 = 0.0; //  h_4
		uinf11 = 0.0; //  h_5 
		uinf12 = 0.0; //  mu
		uinf13 = 0.0; //  kappa
		// uinf2  = D_i[0]; //  D_1
		// uinf3  = D_i[1]; //  D_2
		// uinf4  = D_i[2]; //  D_3 
		// uinf5  = D_i[3]; //  D_4
		// uinf6  = D_i[4]; //  D_5
		// uinf7  = h_i[0]; //  h_1
		// uinf8  = h_i[1]; //  h_2
		// uinf9  = h_i[2]; //  h_3
		// uinf10 = h_i[3]; //  h_4
		// uinf11 = h_i[4]; //  h_5 
		// uinf12 = mix->viscosity() / mu_scale; //  mu
		// uinf13 = mix->frozenThermalConductivity() / kappa_scale; //  kappa
        dT_dUstate(dTdU, Ustate, Uwork, nspecies, ndim, mix);
        nondimensionalize_dT_dUstate(dTdU, (double*)uinf, nspecies, nd);
		uinf14 = dTdU[0];
		uinf15 = dTdU[1];
		uinf16 = dTdU[2];
		uinf17 = dTdU[3];
		uinf18 = dTdU[4];
		uinf19 = dTdU[5];

		T t2 = udg1*udg1;
		T t3 = udg2*udg2;
		T t4 = udg3*udg3;
		T t5 = udg4*udg4;
		T t6 = udg5*udg5;
		T t7 = udg6*udg6;
		T t8 = udg7*udg7;
		T t9 = udg17*udg17;
		T t10 = udg18*udg18;
		T t11 = udg19*udg19;
		T t12 = udg20*udg20;
		T t13 = udg21*udg21;
		T t14 = 1.0/3.141592653589793;
		T t15 = 1.0/param19;
		T t16 = 1.0/param20;
		T t17 = udg1*1.0E+12;
		T t18 = udg2*1.0E+12;
		T t19 = udg3*1.0E+12;
		T t20 = udg4*1.0E+12;
		T t21 = udg5*1.0E+12;
		T t22 = udg17*1.0E+12;
		T t23 = udg18*1.0E+12;
		T t24 = udg19*1.0E+12;
		T t25 = udg20*1.0E+12;
		T t26 = udg21*1.0E+12;
		T t27 = atan(t17);
		T t28 = atan(t18);
		T t29 = atan(t19);
		T t30 = atan(t20);
		T t31 = atan(t21);
		T t32 = atan(t22);
		T t33 = atan(t23);
		T t34 = atan(t24);
		T t35 = atan(t25);
		T t36 = atan(t26);
		T t57 = t2*1.0E+24;
		T t58 = t3*1.0E+24;
		T t59 = t4*1.0E+24;
		T t60 = t5*1.0E+24;
		T t61 = t6*1.0E+24;
		T t62 = t9*1.0E+24;
		T t63 = t10*1.0E+24;
		T t64 = t11*1.0E+24;
		T t65 = t12*1.0E+24;
		T t66 = t13*1.0E+24;
		T t37 = t14*t27;
		T t38 = t14*t28;
		T t39 = t14*t29;
		T t40 = t14*t30;
		T t41 = t14*t31;
		T t42 = t14*t32;
		T t43 = t14*t33;
		T t44 = t14*t34;
		T t45 = t14*t35;
		T t46 = t14*t36;
		T t67 = t57+1.0;
		T t68 = t58+1.0;
		T t69 = t59+1.0;
		T t70 = t60+1.0;
		T t71 = t61+1.0;
		T t72 = t62+1.0;
		T t73 = t63+1.0;
		T t74 = t64+1.0;
		T t75 = t65+1.0;
		T t76 = t66+1.0;
		T t47 = t37+1.0/2.0;
		T t48 = t38+1.0/2.0;
		T t49 = t39+1.0/2.0;
		T t50 = t40+1.0/2.0;
		T t51 = t41+1.0/2.0;
		T t77 = 1.0/t67;
		T t78 = 1.0/t68;
		T t79 = 1.0/t69;
		T t80 = 1.0/t70;
		T t81 = 1.0/t71;
		T t82 = 1.0/t72;
		T t83 = 1.0/t73;
		T t84 = 1.0/t74;
		T t85 = 1.0/t75;
		T t86 = 1.0/t76;
		T t52 = t47*udg1;
		T t53 = t48*udg2;
		T t54 = t49*udg3;
		T t55 = t50*udg4;
		T t56 = t51*udg5;
		T t92 = t14*t17*t77;
		T t93 = t14*t18*t78;
		T t94 = t14*t19*t79;
		T t95 = t14*t20*t80;
		T t96 = t14*t21*t81;
		T t97 = t14*t22*t82;
		T t98 = t14*t23*t83;
		T t99 = t14*t24*t84;
		T t100 = t14*t25*t85;
		T t101 = t14*t26*t86;
		T t87 = t52+3.182454300088011E-13;
		T t88 = t53+3.182454300088011E-13;
		T t89 = t54+3.182454300088011E-13;
		T t90 = t55+3.182454300088011E-13;
		T t91 = t56+3.182454300088011E-13;
		T t102 = t47+t92;
		T t103 = t48+t93;
		T t104 = t49+t94;
		T t105 = t50+t95;
		T t106 = t51+t96;
		T t107 = t42+t97+1.0/2.0;
		T t108 = t43+t98+1.0/2.0;
		T t109 = t44+t99+1.0/2.0;
		T t110 = t45+t100+1.0/2.0;
		T t111 = t46+t101+1.0/2.0;
		T t122 = t52+t53+t54+t55+t56+1.591227150044006E-12;
		T t112 = t102*udg9;
		T t113 = t103*udg10;
		T t114 = t104*udg11;
		T t115 = t105*udg12;
		T t116 = t106*udg13;
		T t117 = t107*udg17;
		T t118 = t108*udg18;
		T t119 = t109*udg19;
		T t120 = t110*udg20;
		T t121 = t111*udg21;
		T t123 = 1.0/t122;
		T t124 = t123*t123;
		T t125 = t123*udg8;
		T t126 = t123*uinf1;
		T t127 = t123*udg6*udg7;
		T t130 = t112*t122;
		T t131 = t113*t122;
		T t132 = t114*t122;
		T t133 = t115*t122;
		T t134 = t116*t122;
		T t135 = t117*t122;
		T t136 = t118*t122;
		T t137 = t119*t122;
		T t138 = t120*t122;
		T t139 = t121*t122;
		T t152 = t112+t113+t114+t115+t116;
		T t153 = t117+t118+t119+t120+t121;
		T t128 = (t7*t124)/2.0;
		T t129 = (t8*t124)/2.0;
		T t140 = -t130;
		T t141 = -t131;
		T t142 = -t132;
		T t143 = -t133;
		T t144 = -t134;
		T t145 = -t135;
		T t146 = -t136;
		T t147 = -t137;
		T t148 = -t138;
		T t149 = -t139;
		T t150 = t125+t126;
		T t154 = t87*t152;
		T t155 = t88*t152;
		T t156 = t89*t152;
		T t157 = t90*t152;
		T t158 = t91*t152;
		T t159 = t87*t153;
		T t160 = t88*t153;
		T t161 = t89*t153;
		T t162 = t90*t153;
		T t163 = t91*t153;
		T t164 = t123*t152*udg6;
		T t165 = t123*t152*udg7;
		T t166 = t123*t153*udg6;
		T t167 = t123*t153*udg7;
		T t151 = t128+t129;
		T t168 = -t164;
		T t169 = -t165;
		T t170 = -t166;
		T t171 = -t167;
		T t176 = t140+t154;
		T t177 = t141+t155;
		T t178 = t142+t156;
		T t179 = t143+t157;
		T t180 = t144+t158;
		T t181 = t145+t159;
		T t182 = t146+t160;
		T t183 = t147+t161;
		T t184 = t148+t162;
		T t185 = t149+t163;
		T t186 = -t123*(t164-udg14);
		T t187 = -t123*(t165-udg15);
		T t188 = -t123*(t166-udg22);
		T t189 = -t123*(t167-udg23);
		T t190 = t123*(t164-udg14)*-2.0;
		T t191 = t123*(t167-udg23)*-2.0;
		T t192 = t123*(t167-udg23);
		T t194 = -t123*uinf2*(t130-t154);
		T t195 = -t124*uinf2*(t130-t154);
		T t196 = -t123*uinf3*(t131-t155);
		T t197 = -t124*uinf3*(t131-t155);
		T t198 = -t123*uinf4*(t132-t156);
		T t199 = -t124*uinf4*(t132-t156);
		T t200 = -t123*uinf5*(t133-t157);
		T t201 = -t124*uinf5*(t133-t157);
		T t202 = -t123*uinf6*(t134-t158);
		T t203 = -t124*uinf6*(t134-t158);
		T t204 = -t123*uinf2*(t135-t159);
		T t205 = -t124*uinf2*(t135-t159);
		T t206 = -t123*uinf3*(t136-t160);
		T t207 = -t124*uinf3*(t136-t160);
		T t208 = -t123*uinf4*(t137-t161);
		T t209 = -t124*uinf4*(t137-t161);
		T t210 = -t123*uinf5*(t138-t162);
		T t211 = -t124*uinf5*(t138-t162);
		T t212 = -t123*uinf6*(t139-t163);
		T t213 = -t124*uinf6*(t139-t163);
		T t214 = t123*uinf2*(t130-t154);
		T t215 = t123*uinf3*(t131-t155);
		T t216 = t123*uinf4*(t132-t156);
		T t217 = t123*uinf5*(t133-t157);
		T t218 = t123*uinf6*(t134-t158);
		T t219 = t123*uinf2*(t135-t159);
		T t220 = t123*uinf3*(t136-t160);
		T t221 = t123*uinf4*(t137-t161);
		T t222 = t123*uinf5*(t138-t162);
		T t223 = t123*uinf6*(t139-t163);
		T t227 = -t16*uinf12*(t123*(t165-udg15)+t123*(t166-udg22));
		T t230 = -t87*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158));
		T t231 = -t88*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158));
		T t232 = -t89*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158));
		T t233 = -t90*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158));
		T t234 = -t91*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158));
		T t235 = -t87*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163));
		T t236 = -t88*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163));
		T t237 = -t89*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163));
		T t238 = -t90*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163));
		T t239 = -t91*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163));
		T t172 = t168+udg14;
		T t173 = t169+udg15;
		T t174 = t170+udg22;
		T t175 = t171+udg23;
		T t193 = t192*2.0;
		T t224 = t187+t188;
		T t226 = t190+t192;
		T t228 = t195+t197+t199+t201+t203;
		T t229 = t205+t207+t209+t211+t213;
		f[0*ng+i] = nlg1*(t214+t230+odg1*t112+t87*t123*udg6)+nlg2*(t219+t235+odg1*t117+t87*t123*udg7)+tau1*(udg1-uhg1);
		f[1*ng+i] = nlg1*(t215+t231+odg1*t113+t88*t123*udg6)+nlg2*(t220+t236+odg1*t118+t88*t123*udg7)+tau2*(udg2-uhg2);
		f[2*ng+i] = nlg1*(t216+t232+odg1*t114+t89*t123*udg6)+nlg2*(t221+t237+odg1*t119+t89*t123*udg7)+tau3*(udg3-uhg3);
		f[3*ng+i] = nlg1*(t217+t233+odg1*t115+t90*t123*udg6)+nlg2*(t222+t238+odg1*t120+t90*t123*udg7)+tau4*(udg4-uhg4);
		f[4*ng+i] = nlg1*(t218+t234+odg1*t116+t91*t123*udg6)+nlg2*(t223+t239+odg1*t121+t91*t123*udg7)+tau5*(udg5-uhg5);
		f[5*ng+i] = nlg2*(t127+t227+odg1*udg22)+tau6*(udg6-uhg6)+nlg1*(uinf1+odg1*udg14+t7*t123-t16*uinf12*(t189+t123*(t164-udg14)*2.0)*(2.0/3.0));
		f[6*ng+i] = nlg1*(t127+t227+odg1*udg15)+tau7*(udg7-uhg7)+nlg2*(uinf1+odg1*udg23+t8*t123+t16*uinf12*(t191+t123*(t164-udg14))*(2.0/3.0));
		f[7*ng+i] = -nlg1*(-odg1*udg16-t150*udg6+uinf7*(t194+t87*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158)))+uinf8*(t196+t88*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158)))+uinf9*(t198+t89*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158)))+uinf10*(t200+t90*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158)))+uinf11*(t202+t91*(t124*uinf2*(t130-t154)+t124*uinf3*(t131-t155)+t124*uinf4*(t132-t156)+t124*uinf5*(t133-t157)+t124*uinf6*(t134-t158)))-t15*t16*uinf13*(uinf19*(udg16+t122*(t124*udg6*(t164-udg14)+t124*udg7*(t165-udg15))-t151*t152)+t112*uinf14+t113*uinf15+t114*uinf16+t115*uinf17+t116*uinf18)+t16*t123*udg6*uinf12*(t189+t123*(t164-udg14)*2.0)*(2.0/3.0)+t16*t123*udg7*uinf12*(t123*(t165-udg15)+t123*(t166-udg22)))-nlg2*(-odg1*udg24-t150*udg7+uinf7*(t204+t87*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163)))+uinf8*(t206+t88*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163)))+uinf9*(t208+t89*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163)))+uinf10*(t210+t90*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163)))+uinf11*(t212+t91*(t124*uinf2*(t135-t159)+t124*uinf3*(t136-t160)+t124*uinf4*(t137-t161)+t124*uinf5*(t138-t162)+t124*uinf6*(t139-t163)))-t15*t16*uinf13*(uinf19*(udg24+t122*(t124*udg6*(t166-udg22)+t124*udg7*(t167-udg23))-t151*t153)+t117*uinf14+t118*uinf15+t119*uinf16+t120*uinf17+t121*uinf18)-t16*t123*udg7*uinf12*(t191+t123*(t164-udg14))*(2.0/3.0)+t16*t123*udg6*uinf12*(t123*(t165-udg15)+t123*(t166-udg22)))+tau8*(udg8-uhg8);
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

		mix->averageDiffusionCoeffs(D_i);
        nondimensionalize_diffusionCoeffs(D_i, (double*)uinf, nspecies, ndim);
        mix->speciesHOverRT(h_i);
        nondimensionalize_enthalpies(h_i, (double*)uinf, nspecies, ndim);


		uinf1  = mix->P()/rhoe_scale;
		// uinf2  = D_i[0]; //  D_1
		// uinf3  = D_i[1]; //  D_2
		// uinf4  = D_i[2]; //  D_3 
		// uinf5  = D_i[3]; //  D_4
		// uinf6  = D_i[4]; //  D_5
		// uinf7  = h_i[0]; //  h_1
		// uinf8  = h_i[1]; //  h_2
		// uinf9  = h_i[2]; //  h_3
		// uinf10 = h_i[3]; //  h_4
		// uinf11 = h_i[4]; //  h_5 
		uinf12 = 0.0; //  mu
		// uinf13 = mix->frozenThermalConductivity() / kappa_scale; //  kappa

        // dT_dUstate(dTdU, Ustate, Uwork, nspecies, ndim, mix);
        // nondimensionalize_dT_dUstate(dTdU, (double*)uinf, nspecies, nd);
		// uinf14 = dTdU[0];
		// uinf15 = dTdU[1];
		// uinf16 = dTdU[2];
		// uinf17 = dTdU[3];
		// uinf18 = dTdU[4];
		// uinf19 = dTdU[5];

		T t2 = udg1*udg1;
		T t3 = udg2*udg2;
		T t4 = udg3*udg3;
		T t5 = udg4*udg4;
		T t6 = udg5*udg5;
		T t7 = udg17*udg17;
		T t8 = udg18*udg18;
		T t9 = udg19*udg19;
		T t10 = udg20*udg20;
		T t11 = udg21*udg21;
		T t12 = 1.0/3.141592653589793;
		T t13 = 1.0/param20;
		T t14 = udg1*1.0E+12;
		T t15 = udg2*1.0E+12;
		T t16 = udg3*1.0E+12;
		T t17 = udg4*1.0E+12;
		T t18 = udg5*1.0E+12;
		T t19 = udg17*1.0E+12;
		T t20 = udg18*1.0E+12;
		T t21 = udg19*1.0E+12;
		T t22 = udg20*1.0E+12;
		T t23 = udg21*1.0E+12;
		T t24 = atan(t14);
		T t25 = atan(t15);
		T t26 = atan(t16);
		T t27 = atan(t17);
		T t28 = atan(t18);
		T t29 = atan(t19);
		T t30 = atan(t20);
		T t31 = atan(t21);
		T t32 = atan(t22);
		T t33 = atan(t23);
		T t54 = t2*1.0E+24;
		T t55 = t3*1.0E+24;
		T t56 = t4*1.0E+24;
		T t57 = t5*1.0E+24;
		T t58 = t6*1.0E+24;
		T t59 = t7*1.0E+24;
		T t60 = t8*1.0E+24;
		T t61 = t9*1.0E+24;
		T t62 = t10*1.0E+24;
		T t63 = t11*1.0E+24;
		T t34 = t12*t24;
		T t35 = t12*t25;
		T t36 = t12*t26;
		T t37 = t12*t27;
		T t38 = t12*t28;
		T t39 = t12*t29;
		T t40 = t12*t30;
		T t41 = t12*t31;
		T t42 = t12*t32;
		T t43 = t12*t33;
		T t64 = t54+1.0;
		T t65 = t55+1.0;
		T t66 = t56+1.0;
		T t67 = t57+1.0;
		T t68 = t58+1.0;
		T t69 = t59+1.0;
		T t70 = t60+1.0;
		T t71 = t61+1.0;
		T t72 = t62+1.0;
		T t73 = t63+1.0;
		T t44 = t34+1.0/2.0;
		T t45 = t35+1.0/2.0;
		T t46 = t36+1.0/2.0;
		T t47 = t37+1.0/2.0;
		T t48 = t38+1.0/2.0;
		T t74 = 1.0/t64;
		T t75 = 1.0/t65;
		T t76 = 1.0/t66;
		T t77 = 1.0/t67;
		T t78 = 1.0/t68;
		T t79 = 1.0/t69;
		T t80 = 1.0/t70;
		T t81 = 1.0/t71;
		T t82 = 1.0/t72;
		T t83 = 1.0/t73;
		T t49 = t44*udg1;
		T t50 = t45*udg2;
		T t51 = t46*udg3;
		T t52 = t47*udg4;
		T t53 = t48*udg5;
		T t84 = t12*t14*t74;
		T t85 = t12*t15*t75;
		T t86 = t12*t16*t76;
		T t87 = t12*t17*t77;
		T t88 = t12*t18*t78;
		T t89 = t12*t19*t79;
		T t90 = t12*t20*t80;
		T t91 = t12*t21*t81;
		T t92 = t12*t22*t82;
		T t93 = t12*t23*t83;
		T t94 = t44+t84;
		T t95 = t45+t85;
		T t96 = t46+t86;
		T t97 = t47+t87;
		T t98 = t48+t88;
		T t99 = t39+t89+1.0/2.0;
		T t100 = t40+t90+1.0/2.0;
		T t101 = t41+t91+1.0/2.0;
		T t102 = t42+t92+1.0/2.0;
		T t103 = t43+t93+1.0/2.0;
		T t114 = t49+t50+t51+t52+t53+1.591227150044006E-12;
		T t104 = t94*udg9;
		T t105 = t95*udg10;
		T t106 = t96*udg11;
		T t107 = t97*udg12;
		T t108 = t98*udg13;
		T t109 = t99*udg17;
		T t110 = t100*udg18;
		T t111 = t101*udg19;
		T t112 = t102*udg20;
		T t113 = t103*udg21;
		T t115 = 1.0/t114;
		T t116 = t115*udg6*udg7;
		T t117 = t104+t105+t106+t107+t108;
		T t118 = t109+t110+t111+t112+t113;
		T t119 = t115*t117*udg6;
		T t120 = t115*t117*udg7;
		T t121 = t115*t118*udg6;
		T t122 = t115*t118*udg7;
		T t123 = -t119;
		T t124 = -t120;
		T t125 = -t121;
		T t126 = -t122;
		T t131 = -t115*(t120-udg15);
		T t132 = -t115*(t121-udg22);
		T t134 = -t13*uinf12*(t115*(t120-udg15)+t115*(t121-udg22));
		T t127 = t123+udg14;
		T t128 = t124+udg15;
		T t129 = t125+udg22;
		T t130 = t126+udg23;
		T t133 = t131+t132;
		f[0*ng+i] = 0.0;
		f[1*ng+i] = 0.0;
		f[2*ng+i] = 0.0;
		f[3*ng+i] = 0.0;
		f[4*ng+i] = 0.0;
		f[5*ng+i] = nlg1*(uinf1+odg1*udg14+t115*(udg6*udg6)-t13*uinf12*(t115*(t119-udg14)*2.0-t115*(t122-udg23))*(2.0/3.0))+nlg2*(t116+t134+odg1*udg22)+tau6*(udg6-uhg6);
		f[6*ng+i] = nlg2*(uinf1+odg1*udg23+t115*(udg7*udg7)+t13*uinf12*(t115*(t119-udg14)-t115*(t122-udg23)*2.0)*(2.0/3.0))+nlg1*(t116+t134+odg1*udg15)+tau7*(udg7-uhg7);
		f[7*ng+i] = 0.0;
	}
}

template <typename T> void opuFbou(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uhg, T *nlg, T *tau, T *uinf, T *param, T time, int modelnumber, int ib, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw, Mutation::Mixture *mix)
{
	if (ib == 1)
    {
        // std::cout << "START FBOU1" << std::endl;
		opuFbou1(f, xdg, udg, odg, wdg, uhg, nlg, tau, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw, mix);
        // std::cout << "END FBOU1" << std::endl;
    }
    else if (ib == 2)
    {
        // std::cout << "START FBOU2" << std::endl;
		opuFbou2(f, xdg, udg, odg, wdg, uhg, nlg, tau, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw, mix);
        // std::cout << "END FBOU2" << std::endl;

    }
	else if (ib == 3)
    {
        // std::cout << "START FBOU3" << std::endl;
		opuFbou3(f, xdg, udg, odg, wdg, uhg, nlg, tau, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw, mix);
        // std::cout << "END FBOU3" << std::endl;

    }
}

template void opuFbou(double *, double *, double *, double *, double *, double *, double *, double *, double *, double *, double, int, int, int, int, int, int, int, int, int, Mutation::Mixture *);
template void opuFbou(float *, float *, float *, float *, float *, float *, float *, float *, float *, float *, float, int, int, int, int, int, int, int, int, int, Mutation::Mixture *);
