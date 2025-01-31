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
        // uinf2  = 0.0; //  D_1
		// uinf3  = 0.0; //  D_2
		// uinf4  = 0.0; //  D_3 
		// uinf5  = 0.0; //  D_4
		// uinf6  = 0.0; //  D_5
		// uinf7  = 0.0; //  h_1
		// uinf8  = 0.0; //  h_2
		// uinf9  = 0.0; //  h_3
		// uinf10 = 0.0; //  h_4
		// uinf11 = 0.0; //  h_5 
		// uinf12 = 0.0; //  mu
		// uinf13 = 0.0; //  kappa
		uinf2  = D_i[0]; //  D_1
		uinf3  = D_i[1]; //  D_2
		uinf4  = D_i[2]; //  D_3 
		uinf5  = D_i[3]; //  D_4
		uinf6  = D_i[4]; //  D_5
		uinf7  = h_i[0]; //  h_1
		uinf8  = h_i[1]; //  h_2
		uinf9  = h_i[2]; //  h_3
		uinf10 = h_i[3]; //  h_4
		uinf11 = h_i[4]; //  h_5 
		uinf12 = mix->viscosity() / mu_scale; //  mu
		uinf13 = mix->frozenThermalConductivity() / kappa_scale; //  kappa

        dT_dUstate(dTdU, Ustate, Uwork, nspecies, ndim, mix);
        nondimensionalize_dT_dUstate(dTdU, (double*)uinf, nspecies, nd);
		uinf14 = dTdU[0];
		uinf15 = dTdU[1];
		uinf16 = dTdU[2];
		uinf17 = dTdU[3];
		uinf18 = dTdU[4];
		uinf19 = dTdU[5];
		// uinf14 = 0.0;
		// uinf15 = 0.0;
		// uinf16 = 0.0;
		// uinf17 = 0.0;
		// uinf18 = 0.0;
		// uinf19 = 0.0;

		T t2 = udg1*udg1;
		T t3 = udg2*udg2;
		T t4 = udg3*udg3;
		T t5 = udg4*udg4;
		T t6 = udg5*udg5;
		T t7 = udg6*udg6;
		T t8 = udg7*udg7;
		T t9 = 1.0/3.141592653589793;
		T t10 = 1.0/param19;
		T t11 = 1.0/param20;
		T t12 = udg1*1.0E+12;
		T t13 = udg2*1.0E+12;
		T t14 = udg3*1.0E+12;
		T t15 = udg4*1.0E+12;
		T t16 = udg5*1.0E+12;
		T t17 = atan(t12);
		T t18 = atan(t13);
		T t19 = atan(t14);
		T t20 = atan(t15);
		T t21 = atan(t16);
		T t37 = t2*1.0E+24;
		T t38 = t3*1.0E+24;
		T t39 = t4*1.0E+24;
		T t40 = t5*1.0E+24;
		T t41 = t6*1.0E+24;
		T t22 = t9*t17;
		T t23 = t9*t18;
		T t24 = t9*t19;
		T t25 = t9*t20;
		T t26 = t9*t21;
		T t42 = t37+1.0;
		T t43 = t38+1.0;
		T t44 = t39+1.0;
		T t45 = t40+1.0;
		T t46 = t41+1.0;
		T t27 = t22+1.0/2.0;
		T t28 = t23+1.0/2.0;
		T t29 = t24+1.0/2.0;
		T t30 = t25+1.0/2.0;
		T t31 = t26+1.0/2.0;
		T t47 = 1.0/t42;
		T t48 = 1.0/t43;
		T t49 = 1.0/t44;
		T t50 = 1.0/t45;
		T t51 = 1.0/t46;
		T t32 = t27*udg1;
		T t33 = t28*udg2;
		T t34 = t29*udg3;
		T t35 = t30*udg4;
		T t36 = t31*udg5;
		T t57 = t9*t12*t47;
		T t58 = t9*t13*t48;
		T t59 = t9*t14*t49;
		T t60 = t9*t15*t50;
		T t61 = t9*t16*t51;
		T t52 = t32+3.182454300088011E-13;
		T t53 = t33+3.182454300088011E-13;
		T t54 = t34+3.182454300088011E-13;
		T t55 = t35+3.182454300088011E-13;
		T t56 = t36+3.182454300088011E-13;
		T t62 = t27+t57;
		T t63 = t28+t58;
		T t64 = t29+t59;
		T t65 = t30+t60;
		T t66 = t31+t61;
		T t77 = t32+t33+t34+t35+t36+1.591227150044006E-12;
		T t67 = t62*udg9;
		T t68 = t63*udg10;
		T t69 = t64*udg11;
		T t70 = t62*udg17;
		T t71 = t65*udg12;
		T t72 = t63*udg18;
		T t73 = t66*udg13;
		T t74 = t64*udg19;
		T t75 = t65*udg20;
		T t76 = t66*udg21;
		T t78 = 1.0/t77;
		T t79 = t78*t78;
		T t80 = t78*udg8;
		T t81 = t78*uinf1;
		T t82 = t78*udg6*udg7;
		T t85 = t67*t77;
		T t86 = t68*t77;
		T t87 = t69*t77;
		T t88 = t70*t77;
		T t89 = t71*t77;
		T t90 = t72*t77;
		T t91 = t73*t77;
		T t92 = t74*t77;
		T t93 = t75*t77;
		T t94 = t76*t77;
		T t107 = t67+t68+t69+t71+t73;
		T t108 = t70+t72+t74+t75+t76;
		T t83 = (t7*t79)/2.0;
		T t84 = (t8*t79)/2.0;
		T t95 = -t85;
		T t96 = -t86;
		T t97 = -t87;
		T t98 = -t88;
		T t99 = -t89;
		T t100 = -t90;
		T t101 = -t91;
		T t102 = -t92;
		T t103 = -t93;
		T t104 = -t94;
		T t105 = t80+t81;
		T t109 = t52*t107;
		T t110 = t53*t107;
		T t111 = t54*t107;
		T t112 = t55*t107;
		T t113 = t56*t107;
		T t114 = t52*t108;
		T t115 = t53*t108;
		T t116 = t54*t108;
		T t117 = t55*t108;
		T t118 = t56*t108;
		T t119 = t78*t107*udg6;
		T t120 = t78*t107*udg7;
		T t121 = t78*t108*udg6;
		T t122 = t78*t108*udg7;
		T t106 = t83+t84;
		T t123 = -t119;
		T t124 = -t120;
		T t125 = -t121;
		T t126 = -t122;
		T t131 = t95+t109;
		T t132 = t96+t110;
		T t133 = t97+t111;
		T t134 = t99+t112;
		T t135 = t101+t113;
		T t136 = t98+t114;
		T t137 = t100+t115;
		T t138 = t102+t116;
		T t139 = t103+t117;
		T t140 = t104+t118;
		T t141 = -t78*(t119-udg14);
		T t142 = -t78*(t120-udg15);
		T t143 = -t78*(t121-udg22);
		T t144 = -t78*(t122-udg23);
		T t145 = t78*(t119-udg14)*-2.0;
		T t146 = t78*(t122-udg23)*-2.0;
		T t147 = t78*(t122-udg23);
		T t149 = -t78*uinf2*(t85-t109);
		T t150 = -t79*uinf2*(t85-t109);
		T t151 = -t78*uinf3*(t86-t110);
		T t152 = -t79*uinf3*(t86-t110);
		T t153 = -t78*uinf4*(t87-t111);
		T t154 = -t79*uinf4*(t87-t111);
		T t155 = -t78*uinf5*(t89-t112);
		T t156 = -t79*uinf5*(t89-t112);
		T t157 = -t78*uinf6*(t91-t113);
		T t158 = -t79*uinf6*(t91-t113);
		T t159 = -t78*uinf2*(t88-t114);
		T t160 = -t79*uinf2*(t88-t114);
		T t161 = -t78*uinf3*(t90-t115);
		T t162 = -t79*uinf3*(t90-t115);
		T t163 = -t78*uinf4*(t92-t116);
		T t164 = -t79*uinf4*(t92-t116);
		T t165 = -t78*uinf5*(t93-t117);
		T t166 = -t79*uinf5*(t93-t117);
		T t167 = -t78*uinf6*(t94-t118);
		T t168 = -t79*uinf6*(t94-t118);
		T t169 = t78*uinf2*(t85-t109);
		T t170 = t78*uinf3*(t86-t110);
		T t171 = t78*uinf4*(t87-t111);
		T t172 = t78*uinf5*(t89-t112);
		T t173 = t78*uinf6*(t91-t113);
		T t174 = t78*uinf2*(t88-t114);
		T t175 = t78*uinf3*(t90-t115);
		T t176 = t78*uinf4*(t92-t116);
		T t177 = t78*uinf5*(t93-t117);
		T t178 = t78*uinf6*(t94-t118);
		T t182 = -t11*uinf12*(t78*(t120-udg15)+t78*(t121-udg22));
		T t185 = -t52*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113));
		T t186 = -t53*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113));
		T t187 = -t54*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113));
		T t188 = -t55*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113));
		T t189 = -t56*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113));
		T t190 = -t52*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118));
		T t191 = -t53*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118));
		T t192 = -t54*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118));
		T t193 = -t55*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118));
		T t194 = -t56*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118));
		T t127 = t123+udg14;
		T t128 = t124+udg15;
		T t129 = t125+udg22;
		T t130 = t126+udg23;
		T t148 = t147*2.0;
		T t179 = t142+t143;
		T t181 = t145+t147;
		T t183 = t150+t152+t154+t156+t158;
		T t184 = t160+t162+t164+t166+t168;
		f[0*ng+i] = nlg1*(t169+t185+odg1*t67+t52*t78*udg6)+nlg2*(t174+t190+odg1*t70+t52*t78*udg7)+tau1*(udg1-uhg1);
		f[1*ng+i] = nlg1*(t170+t186+odg1*t68+t53*t78*udg6)+nlg2*(t175+t191+odg1*t72+t53*t78*udg7)+tau2*(udg2-uhg2);
		f[2*ng+i] = nlg1*(t171+t187+odg1*t69+t54*t78*udg6)+nlg2*(t176+t192+odg1*t74+t54*t78*udg7)+tau3*(udg3-uhg3);
		f[3*ng+i] = nlg1*(t172+t188+odg1*t71+t55*t78*udg6)+nlg2*(t177+t193+odg1*t75+t55*t78*udg7)+tau4*(udg4-uhg4);
		f[4*ng+i] = nlg1*(t173+t189+odg1*t73+t56*t78*udg6)+nlg2*(t178+t194+odg1*t76+t56*t78*udg7)+tau5*(udg5-uhg5);
		f[5*ng+i] = nlg2*(t82+t182+odg1*udg22)+tau6*(udg6-uhg6)+nlg1*(uinf1+odg1*udg14+t7*t78-t11*uinf12*(t144+t78*(t119-udg14)*2.0)*(2.0/3.0));
		f[6*ng+i] = nlg1*(t82+t182+odg1*udg15)+tau7*(udg7-uhg7)+nlg2*(uinf1+odg1*udg23+t8*t78+t11*uinf12*(t146+t78*(t119-udg14))*(2.0/3.0));
		f[7*ng+i] = -nlg1*(-odg1*udg16-t105*udg6+uinf7*(t149+t52*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113)))+uinf8*(t151+t53*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113)))+uinf9*(t153+t54*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113)))+uinf10*(t155+t55*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113)))+uinf11*(t157+t56*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113)))-t10*t11*uinf13*(uinf19*(udg16+t77*(t79*udg6*(t119-udg14)+t79*udg7*(t120-udg15))-t106*t107)+t67*uinf14+t68*uinf15+t69*uinf16+t71*uinf17+t73*uinf18)+t11*t78*udg6*uinf12*(t144+t78*(t119-udg14)*2.0)*(2.0/3.0)+t11*t78*udg7*uinf12*(t78*(t120-udg15)+t78*(t121-udg22)))-nlg2*(-odg1*udg24-t105*udg7+uinf7*(t159+t52*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118)))+uinf8*(t161+t53*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118)))+uinf9*(t163+t54*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118)))+uinf10*(t165+t55*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118)))+uinf11*(t167+t56*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118)))-t10*t11*uinf13*(uinf19*(udg24+t77*(t79*udg6*(t121-udg22)+t79*udg7*(t122-udg23))-t106*t108)+t70*uinf14+t72*uinf15+t74*uinf16+t75*uinf17+t76*uinf18)-t11*t78*udg7*uinf12*(t146+t78*(t119-udg14))*(2.0/3.0)+t11*t78*udg6*uinf12*(t78*(t120-udg15)+t78*(t121-udg22)))+tau8*(udg8-uhg8);
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
        // uinf2  = 0.0; //  D_1
		// uinf3  = 0.0; //  D_2
		// uinf4  = 0.0; //  D_3 
		// uinf5  = 0.0; //  D_4
		// uinf6  = 0.0; //  D_5
		// uinf7  = 0.0; //  h_1
		// uinf8  = 0.0; //  h_2
		// uinf9  = 0.0; //  h_3
		// uinf10 = 0.0; //  h_4
		// uinf11 = 0.0; //  h_5 
		// uinf12 = 0.0; //  mu
		// uinf13 = 0.0; //  kappa
		uinf2  = D_i[0]; //  D_1
		uinf3  = D_i[1]; //  D_2
		uinf4  = D_i[2]; //  D_3 
		uinf5  = D_i[3]; //  D_4
		uinf6  = D_i[4]; //  D_5
		uinf7  = h_i[0]; //  h_1
		uinf8  = h_i[1]; //  h_2
		uinf9  = h_i[2]; //  h_3
		uinf10 = h_i[3]; //  h_4
		uinf11 = h_i[4]; //  h_5 
		uinf12 = mix->viscosity() / mu_scale; //  mu
		uinf13 = mix->frozenThermalConductivity() / kappa_scale; //  kappa
        dT_dUstate(dTdU, Ustate, Uwork, nspecies, ndim, mix);
        nondimensionalize_dT_dUstate(dTdU, (double*)uinf, nspecies, nd);
		uinf14 = dTdU[0];
		uinf15 = dTdU[1];
		uinf16 = dTdU[2];
		uinf17 = dTdU[3];
		uinf18 = dTdU[4];
		uinf19 = dTdU[5];		
		// uinf14 = 0.0;
		// uinf15 = 0.0;
		// uinf16 = 0.0;
		// uinf17 = 0.0;
		// uinf18 = 0.0;
		// uinf19 = 0.0;

		T t2 = udg1*udg1;
		T t3 = udg2*udg2;
		T t4 = udg3*udg3;
		T t5 = udg4*udg4;
		T t6 = udg5*udg5;
		T t7 = udg6*udg6;
		T t8 = udg7*udg7;
		T t9 = 1.0/3.141592653589793;
		T t10 = 1.0/param19;
		T t11 = 1.0/param20;
		T t12 = udg1*1.0E+12;
		T t13 = udg2*1.0E+12;
		T t14 = udg3*1.0E+12;
		T t15 = udg4*1.0E+12;
		T t16 = udg5*1.0E+12;
		T t17 = atan(t12);
		T t18 = atan(t13);
		T t19 = atan(t14);
		T t20 = atan(t15);
		T t21 = atan(t16);
		T t37 = t2*1.0E+24;
		T t38 = t3*1.0E+24;
		T t39 = t4*1.0E+24;
		T t40 = t5*1.0E+24;
		T t41 = t6*1.0E+24;
		T t22 = t9*t17;
		T t23 = t9*t18;
		T t24 = t9*t19;
		T t25 = t9*t20;
		T t26 = t9*t21;
		T t42 = t37+1.0;
		T t43 = t38+1.0;
		T t44 = t39+1.0;
		T t45 = t40+1.0;
		T t46 = t41+1.0;
		T t27 = t22+1.0/2.0;
		T t28 = t23+1.0/2.0;
		T t29 = t24+1.0/2.0;
		T t30 = t25+1.0/2.0;
		T t31 = t26+1.0/2.0;
		T t47 = 1.0/t42;
		T t48 = 1.0/t43;
		T t49 = 1.0/t44;
		T t50 = 1.0/t45;
		T t51 = 1.0/t46;
		T t32 = t27*udg1;
		T t33 = t28*udg2;
		T t34 = t29*udg3;
		T t35 = t30*udg4;
		T t36 = t31*udg5;
		T t57 = t9*t12*t47;
		T t58 = t9*t13*t48;
		T t59 = t9*t14*t49;
		T t60 = t9*t15*t50;
		T t61 = t9*t16*t51;
		T t52 = t32+3.182454300088011E-13;
		T t53 = t33+3.182454300088011E-13;
		T t54 = t34+3.182454300088011E-13;
		T t55 = t35+3.182454300088011E-13;
		T t56 = t36+3.182454300088011E-13;
		T t62 = t27+t57;
		T t63 = t28+t58;
		T t64 = t29+t59;
		T t65 = t30+t60;
		T t66 = t31+t61;
		T t77 = t32+t33+t34+t35+t36+1.591227150044006E-12;
		T t67 = t62*udg9;
		T t68 = t63*udg10;
		T t69 = t64*udg11;
		T t70 = t62*udg17;
		T t71 = t65*udg12;
		T t72 = t63*udg18;
		T t73 = t66*udg13;
		T t74 = t64*udg19;
		T t75 = t65*udg20;
		T t76 = t66*udg21;
		T t78 = 1.0/t77;
		T t79 = t78*t78;
		T t80 = t78*udg8;
		T t81 = t78*uinf1;
		T t82 = t78*udg6*udg7;
		T t85 = t67*t77;
		T t86 = t68*t77;
		T t87 = t69*t77;
		T t88 = t70*t77;
		T t89 = t71*t77;
		T t90 = t72*t77;
		T t91 = t73*t77;
		T t92 = t74*t77;
		T t93 = t75*t77;
		T t94 = t76*t77;
		T t107 = t67+t68+t69+t71+t73;
		T t108 = t70+t72+t74+t75+t76;
		T t83 = (t7*t79)/2.0;
		T t84 = (t8*t79)/2.0;
		T t95 = -t85;
		T t96 = -t86;
		T t97 = -t87;
		T t98 = -t88;
		T t99 = -t89;
		T t100 = -t90;
		T t101 = -t91;
		T t102 = -t92;
		T t103 = -t93;
		T t104 = -t94;
		T t105 = t80+t81;
		T t109 = t52*t107;
		T t110 = t53*t107;
		T t111 = t54*t107;
		T t112 = t55*t107;
		T t113 = t56*t107;
		T t114 = t52*t108;
		T t115 = t53*t108;
		T t116 = t54*t108;
		T t117 = t55*t108;
		T t118 = t56*t108;
		T t119 = t78*t107*udg6;
		T t120 = t78*t107*udg7;
		T t121 = t78*t108*udg6;
		T t122 = t78*t108*udg7;
		T t106 = t83+t84;
		T t123 = -t119;
		T t124 = -t120;
		T t125 = -t121;
		T t126 = -t122;
		T t131 = t95+t109;
		T t132 = t96+t110;
		T t133 = t97+t111;
		T t134 = t99+t112;
		T t135 = t101+t113;
		T t136 = t98+t114;
		T t137 = t100+t115;
		T t138 = t102+t116;
		T t139 = t103+t117;
		T t140 = t104+t118;
		T t141 = -t78*(t119-udg14);
		T t142 = -t78*(t120-udg15);
		T t143 = -t78*(t121-udg22);
		T t144 = -t78*(t122-udg23);
		T t145 = t78*(t119-udg14)*-2.0;
		T t146 = t78*(t122-udg23)*-2.0;
		T t147 = t78*(t122-udg23);
		T t149 = -t78*uinf2*(t85-t109);
		T t150 = -t79*uinf2*(t85-t109);
		T t151 = -t78*uinf3*(t86-t110);
		T t152 = -t79*uinf3*(t86-t110);
		T t153 = -t78*uinf4*(t87-t111);
		T t154 = -t79*uinf4*(t87-t111);
		T t155 = -t78*uinf5*(t89-t112);
		T t156 = -t79*uinf5*(t89-t112);
		T t157 = -t78*uinf6*(t91-t113);
		T t158 = -t79*uinf6*(t91-t113);
		T t159 = -t78*uinf2*(t88-t114);
		T t160 = -t79*uinf2*(t88-t114);
		T t161 = -t78*uinf3*(t90-t115);
		T t162 = -t79*uinf3*(t90-t115);
		T t163 = -t78*uinf4*(t92-t116);
		T t164 = -t79*uinf4*(t92-t116);
		T t165 = -t78*uinf5*(t93-t117);
		T t166 = -t79*uinf5*(t93-t117);
		T t167 = -t78*uinf6*(t94-t118);
		T t168 = -t79*uinf6*(t94-t118);
		T t169 = t78*uinf2*(t85-t109);
		T t170 = t78*uinf3*(t86-t110);
		T t171 = t78*uinf4*(t87-t111);
		T t172 = t78*uinf5*(t89-t112);
		T t173 = t78*uinf6*(t91-t113);
		T t174 = t78*uinf2*(t88-t114);
		T t175 = t78*uinf3*(t90-t115);
		T t176 = t78*uinf4*(t92-t116);
		T t177 = t78*uinf5*(t93-t117);
		T t178 = t78*uinf6*(t94-t118);
		T t182 = -t11*uinf12*(t78*(t120-udg15)+t78*(t121-udg22));
		T t185 = -t52*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113));
		T t186 = -t53*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113));
		T t187 = -t54*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113));
		T t188 = -t55*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113));
		T t189 = -t56*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113));
		T t190 = -t52*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118));
		T t191 = -t53*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118));
		T t192 = -t54*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118));
		T t193 = -t55*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118));
		T t194 = -t56*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118));
		T t127 = t123+udg14;
		T t128 = t124+udg15;
		T t129 = t125+udg22;
		T t130 = t126+udg23;
		T t148 = t147*2.0;
		T t179 = t142+t143;
		T t181 = t145+t147;
		T t183 = t150+t152+t154+t156+t158;
		T t184 = t160+t162+t164+t166+t168;
		f[0*ng+i] = nlg1*(t169+t185+odg1*t67+t52*t78*udg6)+nlg2*(t174+t190+odg1*t70+t52*t78*udg7)+tau1*(udg1-uhg1);
		f[1*ng+i] = nlg1*(t170+t186+odg1*t68+t53*t78*udg6)+nlg2*(t175+t191+odg1*t72+t53*t78*udg7)+tau2*(udg2-uhg2);
		f[2*ng+i] = nlg1*(t171+t187+odg1*t69+t54*t78*udg6)+nlg2*(t176+t192+odg1*t74+t54*t78*udg7)+tau3*(udg3-uhg3);
		f[3*ng+i] = nlg1*(t172+t188+odg1*t71+t55*t78*udg6)+nlg2*(t177+t193+odg1*t75+t55*t78*udg7)+tau4*(udg4-uhg4);
		f[4*ng+i] = nlg1*(t173+t189+odg1*t73+t56*t78*udg6)+nlg2*(t178+t194+odg1*t76+t56*t78*udg7)+tau5*(udg5-uhg5);
		f[5*ng+i] = nlg2*(t82+t182+odg1*udg22)+tau6*(udg6-uhg6)+nlg1*(uinf1+odg1*udg14+t7*t78-t11*uinf12*(t144+t78*(t119-udg14)*2.0)*(2.0/3.0));
		f[6*ng+i] = nlg1*(t82+t182+odg1*udg15)+tau7*(udg7-uhg7)+nlg2*(uinf1+odg1*udg23+t8*t78+t11*uinf12*(t146+t78*(t119-udg14))*(2.0/3.0));
		f[7*ng+i] = -nlg1*(-odg1*udg16-t105*udg6+uinf7*(t149+t52*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113)))+uinf8*(t151+t53*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113)))+uinf9*(t153+t54*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113)))+uinf10*(t155+t55*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113)))+uinf11*(t157+t56*(t79*uinf2*(t85-t109)+t79*uinf3*(t86-t110)+t79*uinf4*(t87-t111)+t79*uinf5*(t89-t112)+t79*uinf6*(t91-t113)))-t10*t11*uinf13*(uinf19*(udg16+t77*(t79*udg6*(t119-udg14)+t79*udg7*(t120-udg15))-t106*t107)+t67*uinf14+t68*uinf15+t69*uinf16+t71*uinf17+t73*uinf18)+t11*t78*udg6*uinf12*(t144+t78*(t119-udg14)*2.0)*(2.0/3.0)+t11*t78*udg7*uinf12*(t78*(t120-udg15)+t78*(t121-udg22)))-nlg2*(-odg1*udg24-t105*udg7+uinf7*(t159+t52*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118)))+uinf8*(t161+t53*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118)))+uinf9*(t163+t54*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118)))+uinf10*(t165+t55*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118)))+uinf11*(t167+t56*(t79*uinf2*(t88-t114)+t79*uinf3*(t90-t115)+t79*uinf4*(t92-t116)+t79*uinf5*(t93-t117)+t79*uinf6*(t94-t118)))-t10*t11*uinf13*(uinf19*(udg24+t77*(t79*udg6*(t121-udg22)+t79*udg7*(t122-udg23))-t106*t108)+t70*uinf14+t72*uinf15+t74*uinf16+t75*uinf17+t76*uinf18)-t11*t78*udg7*uinf12*(t146+t78*(t119-udg14))*(2.0/3.0)+t11*t78*udg6*uinf12*(t78*(t120-udg15)+t78*(t121-udg22)))+tau8*(udg8-uhg8);
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

		// mix->averageDiffusionCoeffs(D_i);
        // nondimensionalize_diffusionCoeffs(D_i, (double*)uinf, nspecies, ndim);
        // mix->speciesHOverRT(h_i);
        // nondimensionalize_enthalpies(h_i, (double*)uinf, nspecies, ndim);


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
		uinf12 = mix->viscosity() / mu_scale; //  mu
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
		T t7 = 1.0/3.141592653589793;
		T t8 = 1.0/param20;
		T t9 = udg1*1.0E+12;
		T t10 = udg2*1.0E+12;
		T t11 = udg3*1.0E+12;
		T t12 = udg4*1.0E+12;
		T t13 = udg5*1.0E+12;
		T t14 = atan(t9);
		T t15 = atan(t10);
		T t16 = atan(t11);
		T t17 = atan(t12);
		T t18 = atan(t13);
		T t34 = t2*1.0E+24;
		T t35 = t3*1.0E+24;
		T t36 = t4*1.0E+24;
		T t37 = t5*1.0E+24;
		T t38 = t6*1.0E+24;
		T t19 = t7*t14;
		T t20 = t7*t15;
		T t21 = t7*t16;
		T t22 = t7*t17;
		T t23 = t7*t18;
		T t39 = t34+1.0;
		T t40 = t35+1.0;
		T t41 = t36+1.0;
		T t42 = t37+1.0;
		T t43 = t38+1.0;
		T t24 = t19+1.0/2.0;
		T t25 = t20+1.0/2.0;
		T t26 = t21+1.0/2.0;
		T t27 = t22+1.0/2.0;
		T t28 = t23+1.0/2.0;
		T t44 = 1.0/t39;
		T t45 = 1.0/t40;
		T t46 = 1.0/t41;
		T t47 = 1.0/t42;
		T t48 = 1.0/t43;
		T t29 = t24*udg1;
		T t30 = t25*udg2;
		T t31 = t26*udg3;
		T t32 = t27*udg4;
		T t33 = t28*udg5;
		T t49 = t7*t9*t44;
		T t50 = t7*t10*t45;
		T t51 = t7*t11*t46;
		T t52 = t7*t12*t47;
		T t53 = t7*t13*t48;
		T t54 = t24+t49;
		T t55 = t25+t50;
		T t56 = t26+t51;
		T t57 = t27+t52;
		T t58 = t28+t53;
		T t69 = t29+t30+t31+t32+t33+1.591227150044006E-12;
		T t59 = t54*udg9;
		T t60 = t55*udg10;
		T t61 = t56*udg11;
		T t62 = t54*udg17;
		T t63 = t57*udg12;
		T t64 = t55*udg18;
		T t65 = t58*udg13;
		T t66 = t56*udg19;
		T t67 = t57*udg20;
		T t68 = t58*udg21;
		T t70 = 1.0/t69;
		T t71 = t70*udg6*udg7;
		T t72 = t59+t60+t61+t63+t65;
		T t73 = t62+t64+t66+t67+t68;
		T t74 = t70*t72*udg6;
		T t75 = t70*t72*udg7;
		T t76 = t70*t73*udg6;
		T t77 = t70*t73*udg7;
		T t78 = -t74;
		T t79 = -t75;
		T t80 = -t76;
		T t81 = -t77;
		T t86 = -t70*(t75-udg15);
		T t87 = -t70*(t76-udg22);
		T t89 = -t8*uinf12*(t70*(t75-udg15)+t70*(t76-udg22));
		T t82 = t78+udg14;
		T t83 = t79+udg15;
		T t84 = t80+udg22;
		T t85 = t81+udg23;
		T t88 = t86+t87;
		f[0*ng+i] = 0.0;
		f[1*ng+i] = 0.0;
		f[2*ng+i] = 0.0;
		f[3*ng+i] = 0.0;
		f[4*ng+i] = 0.0;
		f[5*ng+i] = nlg1*(uinf1+odg1*udg14+t70*(udg6*udg6)-t8*uinf12*(t70*(t74-udg14)*2.0-t70*(t77-udg23))*(2.0/3.0))+nlg2*(t71+t89+odg1*udg22)+tau6*(udg6-uhg6);
		f[6*ng+i] = nlg2*(uinf1+odg1*udg23+t70*(udg7*udg7)+t8*uinf12*(t70*(t74-udg14)-t70*(t77-udg23)*2.0)*(2.0/3.0))+nlg1*(t71+t89+odg1*udg15)+tau7*(udg7-uhg7);
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