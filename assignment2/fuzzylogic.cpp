#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////

//Initialise Fuzzy Rules

void initFuzzyRules(fuzzy_system_rec *fl) {
      const int no_of_rules = 13; // Update the number of rules based on the rule matrix

    // Initializing the input indices for each rule
    for (int i = 0; i < no_of_rules; i++) {
        fl->rules[i].inp_index[0] = in_theta;       // Handle X input (Angle)
        fl->rules[i].inp_index[1] = in_x;       // Handle Y input (Position)
    }
    
   fl->rules[0].inp_fuzzy_set[0] = in_nm;
   fl->rules[0].inp_fuzzy_set[1] = in_pm;
   fl->rules[0].out_fuzzy_set = out_ns;

   fl->rules[1].inp_fuzzy_set[0] = in_nm;
   fl->rules[1].inp_fuzzy_set[1] = in_ze;
   fl->rules[1].out_fuzzy_set = out_nm;

    fl->rules[2].inp_fuzzy_set[0] = in_nm;
    fl->rules[2].inp_fuzzy_set[1] = in_nm;      
    fl->rules[2].out_fuzzy_set = out_nl;

    fl->rules[3].inp_fuzzy_set[0] = in_ns;   
    fl->rules[3].inp_fuzzy_set[1] = in_ps;   
    fl->rules[3].out_fuzzy_set = out_ns;

    fl->rules[4].inp_fuzzy_set[0] = in_ns;   
    fl->rules[4].inp_fuzzy_set[1] = in_ns;   
    fl->rules[4].out_fuzzy_set = out_nm;

    fl->rules[5].inp_fuzzy_set[0] = in_ze;   
    fl->rules[5].inp_fuzzy_set[1] = in_pm;   
    fl->rules[5].out_fuzzy_set = out_ps;

    fl->rules[6].inp_fuzzy_set[0] = in_ze;   
    fl->rules[6].inp_fuzzy_set[1] = in_ze;   
    fl->rules[6].out_fuzzy_set = out_ze;

    fl->rules[7].inp_fuzzy_set[0] = in_ze;   
    fl->rules[7].inp_fuzzy_set[1] = in_nm;   
    fl->rules[7].out_fuzzy_set = out_ns;

    fl->rules[8].inp_fuzzy_set[0] = in_ps;   
    fl->rules[8].inp_fuzzy_set[1] = in_ps;   
    fl->rules[8].out_fuzzy_set = out_ps;

    fl->rules[9].inp_fuzzy_set[0] = in_ps;   
    fl->rules[9].inp_fuzzy_set[1] = in_ns;   
    fl->rules[9].out_fuzzy_set = out_ps;

    fl->rules[10].inp_fuzzy_set[0] = in_pm;   
    fl->rules[10].inp_fuzzy_set[1] = in_pm;  
    fl->rules[10].out_fuzzy_set = out_pl;

    fl->rules[11].inp_fuzzy_set[0] = in_pm;   
    fl->rules[11].inp_fuzzy_set[1] = in_ze;  
    fl->rules[11].out_fuzzy_set = out_pm;

    fl->rules[12].inp_fuzzy_set[0] = in_pm;   
    fl->rules[12].inp_fuzzy_set[1] = in_nm;  
    fl->rules[12].out_fuzzy_set = out_ps;
      return;
}


void initMembershipFunctions(fuzzy_system_rec *fl) {
	
   // X Membership Functions (Theta)
   fl->inp_mem_fns[in_theta][in_nl] = init_trapz(-1.30, -1.30, -1.00, -0.80, left_trapezoid);
   fl->inp_mem_fns[in_theta][in_nm] = init_trapz(-0.55, -0.50, -0.40, -0.30, left_trapezoid);
   fl->inp_mem_fns[in_theta][in_ns] = init_trapz(-0.30, -0.20, -0.10, 0.15, regular_trapezoid);
   fl->inp_mem_fns[in_theta][in_ze] = init_trapz(-0.15, 0.00, 0.00, 0.15, regular_trapezoid);
   fl->inp_mem_fns[in_theta][in_ps] = init_trapz(0.10, 0.20, 0.25, 0.30, regular_trapezoid);
   fl->inp_mem_fns[in_theta][in_pm] = init_trapz(0.30, 0.40, 0.50, 0.60, right_trapezoid);
   fl->inp_mem_fns[in_theta][in_pl] = init_trapz(0.60, 0.70, 0.80, 1.00, right_trapezoid);

   // Y Membership Functions (X)
   fl->inp_mem_fns[in_x][in_nl] = init_trapz(-1.30, -1.30, -1.00, -0.80, left_trapezoid);
   fl->inp_mem_fns[in_x][in_nm] = init_trapz(-0.80, -0.70, -0.50, -0.30, left_trapezoid);
   fl->inp_mem_fns[in_x][in_ns] = init_trapz(-0.50, -0.30, -0.10, 0.10, regular_trapezoid);
   fl->inp_mem_fns[in_x][in_ze] = init_trapz(-0.10, 0.00, 0.00, 0.10, regular_trapezoid);
   fl->inp_mem_fns[in_x][in_ps] = init_trapz(0.10, 0.20, 0.30, 0.50, regular_trapezoid);
   fl->inp_mem_fns[in_x][in_pm] = init_trapz(0.50, 0.70, 0.90, 1.10, right_trapezoid);
   fl->inp_mem_fns[in_x][in_pl] = init_trapz(1.00, 1.20, 1.30, 1.50, right_trapezoid);

	
   return;
}

void initFuzzySystem (fuzzy_system_rec *fl) {

   fl->no_of_inputs = 2;
   fl->no_of_rules = 13;
   fl->no_of_inp_regions = 5;
   fl->no_of_outputs = 7;
	
   coefficient_A= 5.2;
   coefficient_B=0.5;
   coefficient_C=4.6;
   coefficient_D=0.5;
	
   fl->output_values[out_nl] = -230.0;
   fl->output_values[out_nm] = -220.0;
   fl->output_values[out_ns] = -200.0;
   fl->output_values[out_ze] = 0.0;
   fl->output_values[out_ps] = 205.0;
   fl->output_values[out_pm] = 230.0;
   fl->output_values[out_pl] = 245.0;
   

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
