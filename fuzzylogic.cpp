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
//   
   for (i = 0;i < no_of_theta_rules;i++) {
       fl->rules[i].inp_index[0] = INPUT_THETA;
       fl->rules[i].inp_index[1] = INPUT_THETA_DOT;
   }
      
   /* Regions for theta and theta_dot: */
   //sample only
   // fl->rules[0].inp_fuzzy_set[0] = in_nl;
   // fl->rules[0].inp_fuzzy_set[1] = in_nl;

//----------------------------------------------------------------------------   

   // 1
   fl->rules[0].inp_fuzzy_set[0] = in_nl;   
   fl->rules[0].inp_fuzzy_set[1] = in_nl;   
   fl->rules[0].out_fuzzy_set = out_pl;     

   // 2
   fl->rules[1].inp_fuzzy_set[0] = in_nl;
   fl->rules[1].inp_fuzzy_set[1] = in_ns;
   fl->rules[1].out_fuzzy_set = out_pm;

   // 3
   fl->rules[2].inp_fuzzy_set[0] = in_nl;
   fl->rules[2].inp_fuzzy_set[1] = in_ze;
   fl->rules[2].out_fuzzy_set = out_ps;

   // 4
   fl->rules[3].inp_fuzzy_set[0] = in_ns;
   fl->rules[3].inp_fuzzy_set[1] = in_nl;
   fl->rules[3].out_fuzzy_set = out_pm;

   // 5
   fl->rules[4].inp_fuzzy_set[0] = in_ns;
   fl->rules[4].inp_fuzzy_set[1] = in_ns;
   fl->rules[4].out_fuzzy_set = out_ps;

   // 6
   fl->rules[5].inp_fuzzy_set[0] = in_ns;
   fl->rules[5].inp_fuzzy_set[1] = in_ze;
   fl->rules[5].out_fuzzy_set = out_ze;

   // 7
   fl->rules[6].inp_fuzzy_set[0] = in_ze;
   fl->rules[6].inp_fuzzy_set[1] = in_nl;
   fl->rules[6].out_fuzzy_set = out_ns;

   // 8
   fl->rules[7].inp_fuzzy_set[0] = in_ze;
   fl->rules[7].inp_fuzzy_set[1] = in_ns;
   fl->rules[7].out_fuzzy_set = out_nm;

   // 9
   fl->rules[8].inp_fuzzy_set[0] = in_ze;
   fl->rules[8].inp_fuzzy_set[1] = in_ze;
   fl->rules[8].out_fuzzy_set = out_ze;

   // 10
   fl->rules[9].inp_fuzzy_set[0] = in_ps;
   fl->rules[9].inp_fuzzy_set[1] = in_ns;
   fl->rules[9].out_fuzzy_set = out_nm;

   // 11
   fl->rules[10].inp_fuzzy_set[0] = in_ps;
   fl->rules[10].inp_fuzzy_set[1] = in_ze;
   fl->rules[10].out_fuzzy_set = out_ns;

   // 12
   fl->rules[11].inp_fuzzy_set[0] = in_pl;
   fl->rules[11].inp_fuzzy_set[1] = in_ns;
   fl->rules[11].out_fuzzy_set = out_ps;

   // 13
   fl->rules[12].inp_fuzzy_set[0] = in_pl;
   fl->rules[12].inp_fuzzy_set[1] = in_ze;
   fl->rules[12].out_fuzzy_set = out_pl;
   
	
	
//----------------------------------------------------------------------------   
//X vs. X_DOT
//
   for (i = 0;i < no_of_x_rules;i++) {
   	  fl->rules[i + no_of_theta_rules].inp_index[0] = INPUT_X;
   	  fl->rules[i + no_of_theta_rules].inp_index[1] = INPUT_X_DOT;
	}
	  
	/* Regions for x and x_dot: */
   //sample only
   // fl->rules[25+0].inp_fuzzy_set[0] = in_nl;
   // fl->rules[25+0].inp_fuzzy_set[1] = in_nl;

//----------------------------------------------------------------------------  

    // 1
    fl->rules[25].inp_fuzzy_set[0] = in_nl;
    fl->rules[25].inp_fuzzy_set[1] = in_nl;
    fl->rules[25].out_fuzzy_set = out_pvl;  

    // 2
    fl->rules[26].inp_fuzzy_set[0] = in_nl;
    fl->rules[26].inp_fuzzy_set[1] = in_ns;
    fl->rules[26].out_fuzzy_set = out_pl;

    // 3
    fl->rules[27].inp_fuzzy_set[0] = in_nl;
    fl->rules[27].inp_fuzzy_set[1] = in_ze;
    fl->rules[27].out_fuzzy_set = out_pm;

    // 4
    fl->rules[28].inp_fuzzy_set[0] = in_ns;
    fl->rules[28].inp_fuzzy_set[1] = in_nl;
    fl->rules[28].out_fuzzy_set = out_pm;

    // 5
    fl->rules[29].inp_fuzzy_set[0] = in_ns;
    fl->rules[29].inp_fuzzy_set[1] = in_ns;
    fl->rules[29].out_fuzzy_set = out_ps;

    // 6
    fl->rules[30].inp_fuzzy_set[0] = in_ns;
    fl->rules[30].inp_fuzzy_set[1] = in_ze;
    fl->rules[30].out_fuzzy_set = out_ze;

    // 7
    fl->rules[31].inp_fuzzy_set[0] = in_ze;
    fl->rules[31].inp_fuzzy_set[1] = in_nl;
    fl->rules[31].out_fuzzy_set = out_ns;

    // 8
    fl->rules[32].inp_fuzzy_set[0] = in_ze;
    fl->rules[32].inp_fuzzy_set[1] = in_ns;
    fl->rules[32].out_fuzzy_set = out_nm;

    // 9
    fl->rules[33].inp_fuzzy_set[0] = in_ze;
    fl->rules[33].inp_fuzzy_set[1] = in_ze;
    fl->rules[33].out_fuzzy_set = out_ze;

    // 10
    fl->rules[34].inp_fuzzy_set[0] = in_ps;
    fl->rules[34].inp_fuzzy_set[1] = in_ns;
    fl->rules[34].out_fuzzy_set = out_nm;

    // 11
    fl->rules[35].inp_fuzzy_set[0] = in_ps;
    fl->rules[35].inp_fuzzy_set[1] = in_ze;
    fl->rules[35].out_fuzzy_set = out_ns;

    // 12
    fl->rules[36].inp_fuzzy_set[0] = in_pl;
    fl->rules[36].inp_fuzzy_set[1] = in_ns;
    fl->rules[36].out_fuzzy_set = out_ps;

    // 13
    fl->rules[37].inp_fuzzy_set[0] = in_pl;
    fl->rules[37].inp_fuzzy_set[1] = in_ze;
    fl->rules[37].out_fuzzy_set = out_pl;


//----------------------------------------------------------------------------  

   //and so on, and so forth...

   // fl->rules[25+24].out_fuzzy_set = out_nl;
      return;
}


void initMembershipFunctions(fuzzy_system_rec *fl) {
	
   /* The X membership functions */

   //Sample routines only, to give you an idea of what to do here
  	// fl->inp_mem_fns[in_x][in_neg] = init_trapz (0,0,-1.5,-0.5,left_trapezoid);
   //~ fl->inp_mem_fns[in_x][in_ze] = init_trapz (-1.5,-0.5,0.5,1.5,regular_trapezoid);
   //~ fl->inp_mem_fns[in_x][in_pos] = init_trapz (0.5,1.5,0,0,right_trapezoid);

//----------------------------------------------------------------------------------------

   // Input X membership functions //
   fl->inp_mem_fns[INPUT_X][in_nl] = init_trapz(-4.0, -4.0, -3.0, -2.0, left_trapezoid);
   fl->inp_mem_fns[INPUT_X][in_ns] = init_trapz(-3.0, -2.0, -2.0, -1.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_X][in_ze] = init_trapz(-2.0, -1.0, 1.0, 2.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_X][in_ps] = init_trapz(1.0, 2.0, 2.0, 3.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_X][in_pl] = init_trapz(2.0, 3.0, 4.0, 4.0, right_trapezoid);

   // Input Y membership functions //
   fl->inp_mem_fns[INPUT_Y][in_nl] = init_trapz(-4.0, -4.0, -3.0, -2.0, left_trapezoid);
   fl->inp_mem_fns[INPUT_Y][in_ns] = init_trapz(-3.0, -2.0, -2.0, -1.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_Y][in_ze] = init_trapz(-2.0, -1.0, 1.0, 2.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_Y][in_ps] = init_trapz(1.0, 2.0, 2.0, 3.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_Y][in_pl] = init_trapz(2.0, 3.0, 4.0, 4.0, right_trapezoid);


   // The X dot membership functions //
   fl->inp_mem_fns[INPUT_X_DOT][in_nl] = init_trapz(-4.0, -4.0, -3.0, -2.0, left_trapezoid);
   fl->inp_mem_fns[INPUT_X_DOT][in_ns] = init_trapz(-3.0, -2.0, -2.0, -1.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_X_DOT][in_ze] = init_trapz(-2.0, -1.0, 1.0, 2.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_X_DOT][in_ps] = init_trapz(1.0, 2.0, 2.0, 3.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_X_DOT][in_pl] = init_trapz(2.0, 3.0, 4.0, 4.0, right_trapezoid);

   // The theta membership functions //
   fl->inp_mem_fns[INPUT_THETA][in_nl] = init_trapz(-3.5, -3.5, -2.5, -1.5, left_trapezoid);
   fl->inp_mem_fns[INPUT_THETA][in_ns] = init_trapz(-2.5, -1.5, -1.5, -0.5, regular_trapezoid);
   fl->inp_mem_fns[INPUT_THETA][in_ze] = init_trapz(-1.5, -0.5, 0.5, 1.5, regular_trapezoid);
   fl->inp_mem_fns[INPUT_THETA][in_ps] = init_trapz(0.5, 1.5, 1.5, 2.5, regular_trapezoid);
   fl->inp_mem_fns[INPUT_THETA][in_pl] = init_trapz(1.5, 2.5, 3.5, 3.5, right_trapezoid);

   // The theta dot membership functions //
   fl->inp_mem_fns[INPUT_THETA_DOT][in_nl] = init_trapz(-3.0, -3.0, -2.0, -1.0, left_trapezoid);
   fl->inp_mem_fns[INPUT_THETA_DOT][in_ns] = init_trapz(-2.0, -1.0, -1.0, 0.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_THETA_DOT][in_ze] = init_trapz(-1.0, 0.0, 0.0, 1.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_THETA_DOT][in_ps] = init_trapz(0.0, 1.0, 1.0, 2.0, regular_trapezoid);
   fl->inp_mem_fns[INPUT_THETA_DOT][in_pl] = init_trapz(1.0, 2.0, 3.0, 3.0, right_trapezoid);


//----------------------------------------------------------------------------------------


	
   /* The X dot membership functions */
   //enter the appropriate membership function initialisations here 

   /* The theta membership functions */
   //enter the appropriate membership function initialisations here
  	
   /* The theta dot membership functions */
   //enter the appropriate membership function initialisations here
  	

	
	
   return;
}

void initFuzzySystem (fuzzy_system_rec *fl) {

   //Note: The settings of these parameters will depend upon your fuzzy system design
   fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
   fl->no_of_rules = 38;
   fl->no_of_inp_regions = 5;
   fl->no_of_outputs = 9;
	
   coefficient_A=1.0;
   coefficient_B=1.0;   
   coefficient_C=1.0;
   coefficient_D=1.0;
	
	//Sample only
	// fl->output_values [out_nvl]=-95.0;
	// fl->output_values [out_nl] = -85.0;


//----------------------------------------------------------------------------------------

fl->output_values[out_nvl] = -95.0;
fl->output_values[out_nl] = -85.0;
fl->output_values[out_nm] = -60.0;
fl->output_values[out_ns] = -30.0;
fl->output_values[out_ze] = 0.0;
fl->output_values[out_ps] = 30.0;
fl->output_values[out_pm] = 60.0;
fl->output_values[out_pl] = 85.0;
fl->output_values[out_pvl] = 95.0;

//----------------------------------------------------------------------------------------

   

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

