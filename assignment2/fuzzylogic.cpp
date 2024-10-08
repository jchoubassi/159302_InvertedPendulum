#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////

//Initialise Fuzzy Rules

void initFuzzyRules(fuzzy_system_rec *fl) {
	
   const int
      no_of_x_rules = 25,
      no_of_theta_rules = 25;
   
   int i;
	
   //---------------------------------------------------------------------------- 
   //THETA vs. THETA_DOT
   /*
   NL: Negative Large
   NM: Negative Medium
   NS: Negative Small
   ZE: Zero
   PS: Positive Small
   PM: Positive Medium
   PL: Positive Large
   PVL: Positive Very Large
   Nvl: Negative Very Large
   */

   // Initialize input indices for the rules
   for (i = 0; i < no_of_theta_rules; i++) {
      fl->rules[i].inp_index[0] = in_theta; // First input: angle (theta)
      fl->rules[i].inp_index[1] = in_theta_dot;// Second input: angular velocity (theta dot)
   }

   // Define fuzzy rules for THETA vs. THETA_DOT

   // Rule 1
   fl->rules[0].inp_fuzzy_set[0] = in_nvl; // NVL angle
   fl->rules[0].inp_fuzzy_set[1] = in_nvl; // NVL velocity
   fl->rules[0].out_fuzzy_set = out_nvl;   // NVL output

   // Rule 2
   fl->rules[1].inp_fuzzy_set[0] = in_nvl;
   fl->rules[1].inp_fuzzy_set[1] = in_nm;
   fl->rules[1].out_fuzzy_set = out_nl;    // NL output

   // Rule 3
   fl->rules[2].inp_fuzzy_set[0] = in_nvl;
   fl->rules[2].inp_fuzzy_set[1] = in_ns;
   fl->rules[2].out_fuzzy_set = out_nl;    // NL output

   // Rule 4
   fl->rules[3].inp_fuzzy_set[0] = in_nvl;
   fl->rules[3].inp_fuzzy_set[1] = in_ze;
   fl->rules[3].out_fuzzy_set = out_nl;    // NL output

   // Rule 5
   fl->rules[4].inp_fuzzy_set[0] = in_nm;
   fl->rules[4].inp_fuzzy_set[1] = in_nl;
   fl->rules[4].out_fuzzy_set = out_nl;    // NL output

   // Rule 6
   fl->rules[5].inp_fuzzy_set[0] = in_nm;
   fl->rules[5].inp_fuzzy_set[1] = in_nm;
   fl->rules[5].out_fuzzy_set = out_nm;    // NM output

   // Rule 7
   fl->rules[6].inp_fuzzy_set[0] = in_nm;
   fl->rules[6].inp_fuzzy_set[1] = in_ns;
   fl->rules[6].out_fuzzy_set = out_ns;    // NS output

   // Rule 8
   fl->rules[7].inp_fuzzy_set[0] = in_ns;
   fl->rules[7].inp_fuzzy_set[1] = in_nl;
   fl->rules[7].out_fuzzy_set = out_nl;    // NL output

   // Rule 9
   fl->rules[8].inp_fuzzy_set[0] = in_ns;
   fl->rules[8].inp_fuzzy_set[1] = in_ze;
   fl->rules[8].out_fuzzy_set = out_ns;    // NS output

   // Rule 10
   fl->rules[9].inp_fuzzy_set[0] = in_ns;
   fl->rules[9].inp_fuzzy_set[1] = in_ps;
   fl->rules[9].out_fuzzy_set = out_ns;    // NS output

   // Rule 11
   fl->rules[10].inp_fuzzy_set[0] = in_ze;
   fl->rules[10].inp_fuzzy_set[1] = in_nl;
   fl->rules[10].out_fuzzy_set = out_ns;   // NS output

   // Rule 12
   fl->rules[11].inp_fuzzy_set[0] = in_ze;
   fl->rules[11].inp_fuzzy_set[1] = in_ns;
   fl->rules[11].out_fuzzy_set = out_ns;   // NS output

   // Rule 13
   fl->rules[12].inp_fuzzy_set[0] = in_ze;
   fl->rules[12].inp_fuzzy_set[1] = in_ze;
   fl->rules[12].out_fuzzy_set = out_ze;   // ZE output

   // Rule 14
   fl->rules[13].inp_fuzzy_set[0] = in_ze;
   fl->rules[13].inp_fuzzy_set[1] = in_ps;
   fl->rules[13].out_fuzzy_set = out_ps;   // PS output

   // Rule 15
   fl->rules[14].inp_fuzzy_set[0] = in_ps;
   fl->rules[14].inp_fuzzy_set[1] = in_nl;
   fl->rules[14].out_fuzzy_set = out_ze;   // ZE output

   // Rule 16
   fl->rules[15].inp_fuzzy_set[0] = in_ps;
   fl->rules[15].inp_fuzzy_set[1] = in_nm;
   fl->rules[15].out_fuzzy_set = out_ps;   // PS output

   // Rule 17
   fl->rules[16].inp_fuzzy_set[0] = in_ps;
   fl->rules[16].inp_fuzzy_set[1] = in_ze;
   fl->rules[16].out_fuzzy_set = out_ps;   // PS output

   // Rule 18
   fl->rules[17].inp_fuzzy_set[0] = in_ps;
   fl->rules[17].inp_fuzzy_set[1] = in_pm;
   fl->rules[17].out_fuzzy_set = out_pm;   // PM output

   // Rule 19
   fl->rules[18].inp_fuzzy_set[0] = in_pm;
   fl->rules[18].inp_fuzzy_set[1] = in_ze;
   fl->rules[18].out_fuzzy_set = out_pl;   // PL output

   // Rule 20
   fl->rules[19].inp_fuzzy_set[0] = in_pm;
   fl->rules[19].inp_fuzzy_set[1] = in_ps;
   fl->rules[19].out_fuzzy_set = out_pl;   // PL output

   // Rule 21
   fl->rules[20].inp_fuzzy_set[0] = in_pl;
   fl->rules[20].inp_fuzzy_set[1] = in_nl;
   fl->rules[20].out_fuzzy_set = out_ps;   // PS output

   // Rule 22
   fl->rules[21].inp_fuzzy_set[0] = in_pl;
   fl->rules[21].inp_fuzzy_set[1] = in_nm;
   fl->rules[21].out_fuzzy_set = out_pm;   // PM output

   // Rule 23
   fl->rules[22].inp_fuzzy_set[0] = in_pl;
   fl->rules[22].inp_fuzzy_set[1] = in_ps;
   fl->rules[22].out_fuzzy_set = out_pl;   // PL output

   // Rule 24
   fl->rules[23].inp_fuzzy_set[0] = in_pl;
   fl->rules[23].inp_fuzzy_set[1] = in_pl;
   fl->rules[23].out_fuzzy_set = out_pvl;  // PVL output

   // Rule 25
   fl->rules[24].inp_fuzzy_set[0] = in_pvl;
   fl->rules[24].inp_fuzzy_set[1] = in_pvl;
   fl->rules[24].out_fuzzy_set = out_pvl;  // PVL output

      
   //----------------------------------------------------------------------------   
   // X vs. X_DOT
   /*
   NL: Negative Large
   NS: Negative Small
   ZE: Zero
   PS: Positive Small
   PL: Positive Large
   */

   for (i = 0; i < no_of_x_rules; i++) {
      fl->rules[i + 25].inp_index[0] = in_x;     // Start from index 25
      fl->rules[i + 25].inp_index[1] = in_x_dot; // Start from index 25
   }

   // Rules from Yamakawa
   // Rule 1
   fl->rules[0 + 25].inp_fuzzy_set[0] = in_nl;  // x: NL
   fl->rules[0 + 25].inp_fuzzy_set[1] = in_nl;  // x_dot: NL
   fl->rules[0 + 25].out_fuzzy_set = out_nl;     // Output: NL

   // Rule 2
   fl->rules[1 + 25].inp_fuzzy_set[0] = in_nl;  // x: NL
   fl->rules[1 + 25].inp_fuzzy_set[1] = in_ns;  // x_dot: NS
   fl->rules[1 + 25].out_fuzzy_set = out_ze;     // Output: ZE

   // Rule 3
   fl->rules[2 + 25].inp_fuzzy_set[0] = in_nl;  // x: NL
   fl->rules[2 + 25].inp_fuzzy_set[1] = in_ze;  // x_dot: ZE
   fl->rules[2 + 25].out_fuzzy_set = out_nm;     // Output: NM

   // Rule 4
   fl->rules[3 + 25].inp_fuzzy_set[0] = in_nl;  // x: NL
   fl->rules[3 + 25].inp_fuzzy_set[1] = in_ps;  // x_dot: PS
   fl->rules[3 + 25].out_fuzzy_set = out_ze;     // Output: ZE

   // Rule 5
   fl->rules[4 + 25].inp_fuzzy_set[0] = in_nl;  // x: NL
   fl->rules[4 + 25].inp_fuzzy_set[1] = in_pl;  // x_dot: PL
   fl->rules[4 + 25].out_fuzzy_set = out_ns;     // Output: NS

   // Rule 6
   fl->rules[5 + 25].inp_fuzzy_set[0] = in_ns;  // x: NS
   fl->rules[5 + 25].inp_fuzzy_set[1] = in_nl;  // x_dot: NL
   fl->rules[5 + 25].out_fuzzy_set = out_ze;     // Output: ZE

   // Rule 7
   fl->rules[6 + 25].inp_fuzzy_set[0] = in_ns;  // x: NS
   fl->rules[6 + 25].inp_fuzzy_set[1] = in_ns;  // x_dot: NS
   fl->rules[6 + 25].out_fuzzy_set = out_nm;     // Output: NM

   // Rule 8
   fl->rules[7 + 25].inp_fuzzy_set[0] = in_ns;  // x: NS
   fl->rules[7 + 25].inp_fuzzy_set[1] = in_ze;  // x_dot: ZE
   fl->rules[7 + 25].out_fuzzy_set = out_ze;     // Output: ZE

   // Rule 9
   fl->rules[8 + 25].inp_fuzzy_set[0] = in_ns;  // x: NS
   fl->rules[8 + 25].inp_fuzzy_set[1] = in_ps;  // x_dot: PS
   fl->rules[8 + 25].out_fuzzy_set = out_ns;     // Output: NS

   // Rule 10
   fl->rules[9 + 25].inp_fuzzy_set[0] = in_ns;  // x: NS
   fl->rules[9 + 25].inp_fuzzy_set[1] = in_pl;  // x_dot: PL
   fl->rules[9 + 25].out_fuzzy_set = out_ze;     // Output: ZE

   // Rule 11
   fl->rules[10 + 25].inp_fuzzy_set[0] = in_ze; // x: ZE
   fl->rules[10 + 25].inp_fuzzy_set[1] = in_nl; // x_dot: NL
   fl->rules[10 + 25].out_fuzzy_set = out_ns;    // Output: NS

   // Rule 12
   fl->rules[11 + 25].inp_fuzzy_set[0] = in_ze; // x: ZE
   fl->rules[11 + 25].inp_fuzzy_set[1] = in_ns; // x_dot: NS
   fl->rules[11 + 25].out_fuzzy_set = out_ze;    // Output: ZE

   // Rule 13
   fl->rules[12 + 25].inp_fuzzy_set[0] = in_ze; // x: ZE
   fl->rules[12 + 25].inp_fuzzy_set[1] = in_ze; // x_dot: ZE
   fl->rules[12 + 25].out_fuzzy_set = out_ze;    // Output: ZE

   // Rule 14
   fl->rules[13 + 25].inp_fuzzy_set[0] = in_ze; // x: ZE
   fl->rules[13 + 25].inp_fuzzy_set[1] = in_ps; // x_dot: PS
   fl->rules[13 + 25].out_fuzzy_set = out_ze;    // Output: ZE

   // Rule 15
   fl->rules[14 + 25].inp_fuzzy_set[0] = in_ze; // x: ZE
   fl->rules[14 + 25].inp_fuzzy_set[1] = in_pl; // x_dot: PL
   fl->rules[14 + 25].out_fuzzy_set = out_ps;    // Output: PS

   // Rule 16
   fl->rules[15 + 25].inp_fuzzy_set[0] = in_ps; // x: PS
   fl->rules[15 + 25].inp_fuzzy_set[1] = in_nl; // x_dot: NL
   fl->rules[15 + 25].out_fuzzy_set = out_ze;    // Output: ZE

   // Rule 17
   fl->rules[16 + 25].inp_fuzzy_set[0] = in_ps; // x: PS
   fl->rules[16 + 25].inp_fuzzy_set[1] = in_ns; // x_dot: NS
   fl->rules[16 + 25].out_fuzzy_set = out_ps;    // Output: PS

   // Rule 18
   fl->rules[17 + 25].inp_fuzzy_set[0] = in_ps; // x: PS
   fl->rules[17 + 25].inp_fuzzy_set[1] = in_ze; // x_dot: ZE
   fl->rules[17 + 25].out_fuzzy_set = out_ze;    // Output: ZE

   // Rule 19
   fl->rules[18 + 25].inp_fuzzy_set[0] = in_ps; // x: PS
   fl->rules[18 + 25].inp_fuzzy_set[1] = in_ps; // x_dot: PS
   fl->rules[18 + 25].out_fuzzy_set = out_pm;    // Output: PM

   // Rule 20
   fl->rules[19 + 25].inp_fuzzy_set[0] = in_ps; // x: PS
   fl->rules[19 + 25].inp_fuzzy_set[1] = in_pl; // x_dot: PL
   fl->rules[19 + 25].out_fuzzy_set = out_ze;    // Output: ZE

   // Rule 21
   fl->rules[20 + 25].inp_fuzzy_set[0] = in_pl; // x: PL
   fl->rules[20 + 25].inp_fuzzy_set[1] = in_nl; // x_dot: NL
   fl->rules[20 + 25].out_fuzzy_set = out_ps;    // Output: PS

   // Rule 22
   fl->rules[21 + 25].inp_fuzzy_set[0] = in_pl; // x: PL
   fl->rules[21 + 25].inp_fuzzy_set[1] = in_ns; // x_dot: NS
   fl->rules[21 + 25].out_fuzzy_set = out_ze;    // Output: ZE

   // Rule 23
   fl->rules[22 + 25].inp_fuzzy_set[0] = in_pl; // x: PL
   fl->rules[22 + 25].inp_fuzzy_set[1] = in_ze; // x_dot: ZE
   fl->rules[22 + 25].out_fuzzy_set = out_pm;    // Output: PM
   // Rule 24
   fl->rules[23 + 25].inp_fuzzy_set[0] = in_pl; // x: PL
   fl->rules[23 + 25].inp_fuzzy_set[1] = in_ps; // x_dot: PS
   fl->rules[23 + 25].out_fuzzy_set = out_pl;    // Output: PL

   // Rule 25
   fl->rules[24 + 25].inp_fuzzy_set[0] = in_pl; // x: PL
   fl->rules[24 + 25].inp_fuzzy_set[1] = in_pl; // x_dot: PL
   fl->rules[24 + 25].out_fuzzy_set = out_pvl;    // Output: PVL
      
   return;
}


void initMembershipFunctions(fuzzy_system_rec *fl) {
	
   /* The X membership functions */
   fl->inp_mem_fns[in_x][in_nvl] = init_trapz(-4.0, -4.0, -3.5, -3.0, left_trapezoid); // NVL
   fl->inp_mem_fns[in_x][in_nl] = init_trapz(-3.5, -3.5, -3.0, -2.0, left_trapezoid); // NL
   fl->inp_mem_fns[in_x][in_nm] = init_trapz(-3.0, -2.0, -1.0, 0.0, regular_trapezoid); // NM
   fl->inp_mem_fns[in_x][in_ns] = init_trapz(-2.0, -1.0, 0.0, 1.0, regular_trapezoid); // NS
   fl->inp_mem_fns[in_x][in_ze] = init_trapz(-0.5, 0, 0, 0.5, regular_trapezoid);     // ZE
   fl->inp_mem_fns[in_x][in_ps] = init_trapz(0.0, 1.0, 2.0, 3.0, regular_trapezoid);   // PS
   fl->inp_mem_fns[in_x][in_pm] = init_trapz(1.0, 2.0, 3.0, 4.0, regular_trapezoid);   // PM
   fl->inp_mem_fns[in_x][in_pl] = init_trapz(3.0, 4.0, 4.0, 4.0, right_trapezoid);     // PL
   fl->inp_mem_fns[in_x][in_pvl] = init_trapz(4.0, 4.0, 4.0, 5.0, right_trapezoid);    // PVL

   /* The X dot membership functions */
   fl->inp_mem_fns[in_x_dot][in_nvl] = init_trapz(-4.0, -4.0, -3.5, -3.0, left_trapezoid); // NVL
   fl->inp_mem_fns[in_x_dot][in_nl] = init_trapz(-3.5, -3.5, -3.0, -2.0, left_trapezoid); // NL
   fl->inp_mem_fns[in_x_dot][in_nm] = init_trapz(-3.0, -2.0, -1.0, 0.0, regular_trapezoid); // NM
   fl->inp_mem_fns[in_x_dot][in_ns] = init_trapz(-2.0, -1.0, 0.0, 1.0, regular_trapezoid); // NS
   fl->inp_mem_fns[in_x_dot][in_ze] = init_trapz(-0.5, 0, 0, 0.5, regular_trapezoid);     // ZE
   fl->inp_mem_fns[in_x_dot][in_ps] = init_trapz(0.0, 1.0, 2.0, 3.0, regular_trapezoid);   // PS
   fl->inp_mem_fns[in_x_dot][in_pm] = init_trapz(1.0, 2.0, 3.0, 4.0, regular_trapezoid);   // PM
   fl->inp_mem_fns[in_x_dot][in_pl] = init_trapz(3.0, 4.0, 4.0, 4.0, right_trapezoid);     // PL
   fl->inp_mem_fns[in_x_dot][in_pvl] = init_trapz(4.0, 4.0, 4.0, 5.0, right_trapezoid);    // PVL

   /* The theta membership functions */
   fl->inp_mem_fns[in_theta][in_nvl] = init_trapz(-4.0, -4.0, -3.5, -3.0, left_trapezoid); // NVL
   fl->inp_mem_fns[in_theta][in_nl] = init_trapz(-3.5, -3.5, -3.0, -2.0, left_trapezoid); // NL
   fl->inp_mem_fns[in_theta][in_nm] = init_trapz(-3.0, -2.0, -1.0, 0.0, regular_trapezoid); // NM
   fl->inp_mem_fns[in_theta][in_ns] = init_trapz(-2.0, -1.0, 0.0, 1.0, regular_trapezoid); // NS
   fl->inp_mem_fns[in_theta][in_ze] = init_trapz(-0.5, 0, 0, 0.5, regular_trapezoid);     // ZE
   fl->inp_mem_fns[in_theta][in_ps] = init_trapz(0.0, 1.0, 2.0, 3.0, regular_trapezoid);   // PS
   fl->inp_mem_fns[in_theta][in_pm] = init_trapz(1.0, 2.0, 3.0, 4.0, regular_trapezoid);   // PM
   fl->inp_mem_fns[in_theta][in_pl] = init_trapz(3.0, 4.0, 4.0, 4.0, right_trapezoid);     // PL
   fl->inp_mem_fns[in_theta][in_pvl] = init_trapz(4.0, 4.0, 4.0, 5.0, right_trapezoid);    // PVL

   /* The theta dot membership functions */
   fl->inp_mem_fns[in_theta_dot][in_nvl] = init_trapz(-4.0, -4.0, -3.5, -3.0, left_trapezoid); // NVL
   fl->inp_mem_fns[in_theta_dot][in_nl] = init_trapz(-3.5, -3.5, -3.0, -2.0, left_trapezoid); // NL
   fl->inp_mem_fns[in_theta_dot][in_nm] = init_trapz(-3.0, -2.0, -1.0, 0.0, regular_trapezoid); // NM
   fl->inp_mem_fns[in_theta_dot][in_ns] = init_trapz(-2.0, -1.0, 0.0, 1.0, regular_trapezoid); // NS
   fl->inp_mem_fns[in_theta_dot][in_ze] = init_trapz(-0.5, 0, 0, 0.5, regular_trapezoid);     // ZE
   fl->inp_mem_fns[in_theta_dot][in_ps] = init_trapz(0.0, 1.0, 2.0, 3.0, regular_trapezoid);   // PS
   fl->inp_mem_fns[in_theta_dot][in_pm] = init_trapz(1.0, 2.0, 3.0, 4.0, regular_trapezoid);   // PM
   fl->inp_mem_fns[in_theta_dot][in_pl] = init_trapz(3.0, 4.0, 4.0, 4.0, right_trapezoid);     // PL
   fl->inp_mem_fns[in_theta_dot][in_pvl] = init_trapz(4.0, 4.0, 4.0, 5.0, right_trapezoid);    // PVL


   return;
}

void initFuzzySystem (fuzzy_system_rec *fl) {

   //Note: The settings of these parameters will depend upon your fuzzy system design
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 50;
   fl->no_of_inp_regions = 5;
   fl->no_of_outputs = 9;

   //adjust
   coefficient_A=2.0;
   coefficient_B=1.0;
   coefficient_C=0.5;
   coefficient_D=1.0;
	
   // Output val
   fl->output_values [out_nvl]= -120.0;
   fl->output_values [out_nl]= -80.0;
   fl->output_values [out_nm]= -50.0;
   fl->output_values [out_ns]= -20.0;
   fl->output_values [out_ze]= 0.0;
   fl->output_values [out_ps]= 20.0;
   fl->output_values [out_pm]= 50.0;
   fl->output_values [out_pl]= 80.0;
   fl->output_values [out_pvl]= 120.0;



   fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
   initFuzzyRules(fl);
   initMembershipFunctions(fl);
   return;
}

//////////////////////////////////////////////////////////////////////////////

trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ) {
   
   trapezoid trz;
   trz.a = x1;
   trz.b = x2;
   trz.c = x3;
   trz.d = x4;
   trz.tp = typ;
   switch (trz.tp) {
      
      case regular_trapezoid:
             trz.l_slope = 1.0/(trz.b - trz.a);
             trz.r_slope = 1.0/(trz.c - trz.d);
             break;
    
      case left_trapezoid: //2024, corrected version - to match variables used in the lectures - (c, d) instead of (a,b)
             trz.r_slope = 1.0/(trz.c - trz.d);
             trz.l_slope = 0.0;
             break;
    
      case right_trapezoid:
             trz.l_slope = 1.0/(trz.b - trz.a);
             trz.r_slope = 0.0;
             break;
   }  /* end switch  */
   
   return trz;
}  /* end function */

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
float trapz (float x, trapezoid trz) {
   switch (trz.tp) {
       
      case left_trapezoid: //2024, corrected version - to match variables used in the lectures - (c, d) instead of (a,b)
             if (x <= trz.c)
                return 1.0;
             if (x >= trz.d)
                return 0.0;
             /* c < x < d */
             return trz.r_slope * (x - trz.d);
     
     
      case right_trapezoid:
             if (x <= trz.a)
                return 0.0;
             if (x >= trz.b)
                return 1.0;
             /* a < x < b */
             return trz.l_slope * (x - trz.a);
     
      case regular_trapezoid:
             if ((x <= trz.a) || (x >= trz.d))
                return 0.0;
             if ((x >= trz.b) && (x <= trz.c))
                return 1.0;
             if ((x >= trz.a) && (x <= trz.b))
                return trz.l_slope * (x - trz.a);
             if ((x >= trz.c) && (x <= trz.d))
                return  trz.r_slope * (x - trz.d);
                
     }  /* End switch  */
     
   return 0.0;  /* should not get to this point */
}  /* End function */

//////////////////////////////////////////////////////////////////////////////
float min_of(float values[],int no_of_inps) {
   int i;
   float val;
   val = values [0];
   for (i = 1;i < no_of_inps;i++) {
       if (values[i] < val)
	  val = values [i];
   }
   return val;
}



//////////////////////////////////////////////////////////////////////////////
float fuzzy_system (float inputs[],fuzzy_system_rec fz) {
   int i,j;
   short variable_index,fuzzy_set;
   float sum1 = 0.0,sum2 = 0.0,weight;
   float m_values[MAX_NO_OF_INPUTS];
	
   
   for (i = 0;i < fz.no_of_rules;i++) {
      for (j = 0;j < fz.no_of_inputs;j++) {
	   variable_index = fz.rules[i].inp_index[j];
	   fuzzy_set = fz.rules[i].inp_fuzzy_set[j];
	   m_values[j] = trapz(inputs[variable_index],
	       fz.inp_mem_fns[variable_index][fuzzy_set]);
	   } /* end j  */
      
       weight = min_of (m_values,fz.no_of_inputs);
				
       sum1 += weight * fz.output_values[fz.rules[i].out_fuzzy_set];
       sum2 += weight;
   } /* end i  */
 
	
	if (fabs(sum2) < TOO_SMALL) {
      cout << "\r\nFLPRCS Error: Sum2 in fuzzy_system is 0.  Press key: " << endl;
      //~ getch();
      //~ exit(1);
      return 0.0;
   }
   
   return (sum1/sum2);
}  /* end fuzzy_system  */

//////////////////////////////////////////////////////////////////////////////
void free_fuzzy_rules (fuzzy_system_rec *fz) {
   if (fz->allocated){
	   free (fz->rules);
	}
	
   fz->allocated = false;
   return;
}

