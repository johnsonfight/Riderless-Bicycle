void FuzzySetup(){
/* fuzzy set : input & output
    input1: sliding surface -> input_S
    input2: sliding surface rate -> input_dS
    output: control PWM
    membership function : 
*/
  // Step 2 - Creating a FuzzyInput 

 FuzzyInput* input_S = new FuzzyInput(1);// With its ID in param
 FuzzyInput* input_dS = new FuzzyInput(2);// With its ID in param 
 // Step 3 - Creating FuzzyOutput velocity
 FuzzyOutput* PWM_output = new FuzzyOutput(1);// With its ID in param
    // Creating the FuzzySet to compond FuzzyInput sliding surface 
 FuzzySet* S_PB = new FuzzySet(0.65, 1, 5, 5);   //  Sliding surface is positive big
 input_S->addFuzzySet(S_PB); // Add FuzzySet PB to input_S
 FuzzySet* S_PM = new FuzzySet(0.3, 0.65, 0.65, 1.0);  // Sliding surface is positive medium
 input_S->addFuzzySet(S_PM); // Add FuzzySet PM to input_S
 FuzzySet* S_PS = new FuzzySet(0, 0.3, 0.3, 0.65); // Sliding surface is positive small
 input_S->addFuzzySet(S_PS); // Add FuzzySet PS to input_S
 FuzzySet* S_ZO = new FuzzySet(-0.3, 0, 0, 0.3); // Sliding surface is zero
 input_S->addFuzzySet(S_ZO); // Add FuzzySet ZO to input_S
 FuzzySet* S_NS = new FuzzySet(-0.65, -0.3, -0.3, 0); //  Sliding surface is negative small
 input_S->addFuzzySet(S_NS); // Add FuzzySet NS to input_S
 FuzzySet* S_NM = new FuzzySet(-1, -0.65, -0.65, -0.30); // Sliding surface is negative medium
 input_S->addFuzzySet(S_NM); // Add FuzzySet NM to input_S
 FuzzySet* S_NB = new FuzzySet(-5, -5, -1, -0.65); // Sliding surface is negative big
 input_S->addFuzzySet(S_NB); // Add FuzzySet NB to input_S
 
 Bikefuzzy->addFuzzyInput(input_S);  // Add FuzzyInput1 to Fuzzy object
 
 // Creating the FuzzySet to compond FuzzyInput sliding surface 
 FuzzySet* dS_PB = new FuzzySet(6.5, 10, 20, 20); // Sliding surface rate is positive big
 input_dS->addFuzzySet(dS_PB); // Add FuzzySet PB to input_dS
 FuzzySet* dS_PM = new FuzzySet(3, 6.5, 6.5, 10.0);  // Sliding surface rate is positive medium
 input_dS->addFuzzySet(dS_PM); // Add FuzzySet PM to input_dS
 FuzzySet* dS_PS = new FuzzySet(0, 3, 3, 6.5); // Sliding surface rate is positive small
 input_dS->addFuzzySet(dS_PS); // Add FuzzySet PS to input_dS
 FuzzySet* dS_ZO = new FuzzySet(-3, 0, 0, 3); // Sliding surface rate is zero
 input_dS->addFuzzySet(dS_ZO); // Add FuzzySet ZO to input_dS
 FuzzySet* dS_NS = new FuzzySet(-6.5, -3, -3, 0); //  Sliding surface rate is negative small
 input_dS->addFuzzySet(dS_NS); // Add FuzzySet NS to input_dS
 FuzzySet* dS_NM = new FuzzySet(-10, -6.5, -6.5, -3); // Sliding surface rate is negative medium
 input_dS->addFuzzySet(dS_NM); // Add FuzzySet NM to input_dS
 FuzzySet* dS_NB = new FuzzySet(-20, -20, -10, -6.5); // Sliding surface rate is negative big
 input_dS->addFuzzySet(dS_NB); // Add FuzzySet NB to input_dS
 
 Bikefuzzy->addFuzzyInput(input_dS); // Add FuzzyInput2 to Fuzzy object
   
 // Creating FuzzySet to compond FuzzyOutput velocity
 FuzzySet* u_PB = new FuzzySet(0.65, 1, 3, 3);   //  Sliding surface is positive big
 PWM_output->addFuzzySet(u_PB); // Add FuzzySet PB to output_u
 FuzzySet* u_PM = new FuzzySet(0.30, 0.65, 0.65, 1.0);  // Sliding surface is positive medium
 PWM_output->addFuzzySet(u_PM); // Add FuzzySet PM to output_u
 FuzzySet* u_PS = new FuzzySet(0, 0.30, 0.30, 0.65); // Sliding surface is positive small
 PWM_output->addFuzzySet(u_PS); // Add FuzzySet PS to output_u
 FuzzySet* u_ZO = new FuzzySet(-0.30, 0, 0, 0.30); // Sliding surface is zero
 PWM_output->addFuzzySet(u_ZO); // Add FuzzySet ZO to output_u
 FuzzySet* u_NS = new FuzzySet(-0.65, -0.30, -0.30, 0); //  Sliding surface is negative small
 PWM_output->addFuzzySet(u_NS); // Add FuzzySet NS to output_u
 FuzzySet* u_NM = new FuzzySet(-1, -0.65, -0.65, -0.30); // Sliding surface is negative medium
 PWM_output->addFuzzySet(u_NM); // Add FuzzySet NM to output_u
 FuzzySet* u_NB = new FuzzySet(-3, -3, -1, -0.65); // Sliding surface is negative big
 PWM_output->addFuzzySet(u_NB); // Add FuzzySet NB to output_u
 
 Bikefuzzy->addFuzzyOutput(PWM_output); // Add FuzzyOutput to Fuzzy object
 
/*           Rule Table             */ 

//========================================================Rule 1-7============================================================================
 //Passo 4 - Assembly the Fuzzy rules
 FuzzyRuleConsequent* then_u_NB = new FuzzyRuleConsequent(); // Instantiating a Consequent to expression
 then_u_NB->addOutput(u_NB);// Adding corresponding FuzzySet to Consequent object
 FuzzyRuleConsequent* then_u_NM = new FuzzyRuleConsequent(); // Instantiating a Consequent to expression
 then_u_NM->addOutput(u_NM);// Adding corresponding FuzzySet to Consequent object
 FuzzyRuleConsequent* then_u_NS = new FuzzyRuleConsequent(); // Instantiating a Consequent to expression
 then_u_NS->addOutput(u_NS);// Adding corresponding FuzzySet to Consequent object
 FuzzyRuleConsequent* then_u_ZO = new FuzzyRuleConsequent(); // Instantiating a Consequent to expression
 then_u_ZO->addOutput(u_ZO);// Adding corresponding FuzzySet to Consequent object
 FuzzyRuleConsequent* then_u_PS = new FuzzyRuleConsequent(); // Instantiating a Consequent to expression
 then_u_PS->addOutput(u_PS);// Adding corresponding FuzzySet to Consequent object
 FuzzyRuleConsequent* then_u_PM = new FuzzyRuleConsequent(); // Instantiating a Consequent to expression
 then_u_PM->addOutput(u_PM);// Adding corresponding FuzzySet to Consequent object
 FuzzyRuleConsequent* then_u_PB = new FuzzyRuleConsequent(); // Instantiating a Consequent to expression
 then_u_PB->addOutput(u_PB);// Adding corresponding FuzzySet to Consequent object 
 
 
 // FuzzyRule1 "IF S = PB AND dS = PB, THEN u = NB "
 FuzzyRuleAntecedent* if_S_PB_AND_dS_PB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PB_AND_dS_PB->joinWithAND( S_PB, dS_PB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule01 = new FuzzyRule(1, if_S_PB_AND_dS_PB, then_u_NB); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule01); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule2 "IF S = PB AND dS = PM, THEN u = NB "
 FuzzyRuleAntecedent* if_S_PB_AND_dS_PM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PB_AND_dS_PM->joinWithAND( S_PB, dS_PM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule02 = new FuzzyRule(2, if_S_PB_AND_dS_PM, then_u_NB); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule02); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule3 "IF S = PB AND dS = PS, THEN u = NM "
 FuzzyRuleAntecedent* if_S_PB_AND_dS_PS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PB_AND_dS_PS->joinWithAND( S_PB, dS_PS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule03 = new FuzzyRule(3, if_S_PB_AND_dS_PS, then_u_NM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule03); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule4 "IF S = PB AND dS = ZO, THEN u = NM "
 FuzzyRuleAntecedent* if_S_PB_AND_dS_ZO = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PB_AND_dS_ZO->joinWithAND( S_PB, dS_ZO); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule04 = new FuzzyRule(4, if_S_PB_AND_dS_ZO, then_u_NM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule04); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule5 "IF S = PB AND dS = NS, THEN u = NS "
 FuzzyRuleAntecedent*  if_S_PB_AND_dS_NS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PB_AND_dS_NS->joinWithAND( S_PB, dS_NS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule05 = new FuzzyRule(5, if_S_PB_AND_dS_NS, then_u_NS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule05); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule6 "IF S = PB AND dS = NM, THEN u = NS "
 FuzzyRuleAntecedent* if_S_PB_AND_dS_NM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PB_AND_dS_NM->joinWithAND( S_PB, dS_NM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule06 = new FuzzyRule(6, if_S_PB_AND_dS_NM, then_u_NS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule06); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule7 "IF S = PB AND dS = NB, THEN u = ZO "
 FuzzyRuleAntecedent* if_S_PB_AND_dS_NB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PB_AND_dS_NB->joinWithAND( S_PB, dS_NB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule07 = new FuzzyRule(7, if_S_PB_AND_dS_NB, then_u_ZO); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule07); // Adding FuzzyRule to Fuzzy object
 
//========================================================Rule 8-14============================================================================

 // FuzzyRule8 "IF S = PM AND dS = PB, THEN u = NB "
 FuzzyRuleAntecedent* if_S_PM_AND_dS_PB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PM_AND_dS_PB->joinWithAND( S_PM, dS_PB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule08 = new FuzzyRule(8, if_S_PM_AND_dS_PB, then_u_NB); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule08); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule9 "IF S = PM AND dS = PM, THEN u = NM "
 FuzzyRuleAntecedent* if_S_PM_AND_dS_PM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PM_AND_dS_PM->joinWithAND( S_PM, dS_PM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule09 = new FuzzyRule(9, if_S_PM_AND_dS_PM, then_u_NM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule09); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule10 "IF S = PM AND dS = PS, THEN u = NM "
 FuzzyRuleAntecedent* if_S_PM_AND_dS_PS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PM_AND_dS_PS->joinWithAND( S_PM, dS_PS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule10 = new FuzzyRule(10, if_S_PM_AND_dS_PS, then_u_NM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule10); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule11 "IF S = PM AND dS = ZO, THEN u = NS "
 FuzzyRuleAntecedent* if_S_PM_AND_dS_ZO = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PM_AND_dS_ZO->joinWithAND( S_PM, dS_ZO); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule11 = new FuzzyRule(11, if_S_PM_AND_dS_ZO, then_u_NS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule11); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule12 "IF S = PM AND dS = NS, THEN u = NS "
 FuzzyRuleAntecedent*  if_S_PM_AND_dS_NS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PM_AND_dS_NS->joinWithAND( S_PM, dS_NS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule12 = new FuzzyRule(12, if_S_PM_AND_dS_NS, then_u_NS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule12); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule13 "IF S = PM AND dS = NM, THEN u = ZO "
 FuzzyRuleAntecedent* if_S_PM_AND_dS_NM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PM_AND_dS_NM->joinWithAND( S_PM, dS_NM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule13 = new FuzzyRule(13, if_S_PM_AND_dS_NM, then_u_ZO); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule13); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule14 "IF S = PM AND dS = NB, THEN u = PS "
 FuzzyRuleAntecedent* if_S_PM_AND_dS_NB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PM_AND_dS_NB->joinWithAND( S_PM, dS_NB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule14 = new FuzzyRule(14, if_S_PM_AND_dS_NB, then_u_PS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule14); // Adding FuzzyRule to Fuzzy object
  
 //========================================================Rule 15-21 ============================================================================

 // FuzzyRule15 "IF S = PS AND dS = PB, THEN u = NM "
 FuzzyRuleAntecedent* if_S_PS_AND_dS_PB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PS_AND_dS_PB->joinWithAND( S_PS, dS_PB); // Adding corresponding FuzzySet to Antecedent object
 // Instantiating a FuzzyRule object
 FuzzyRule* fuzzyRule15 = new FuzzyRule(15, if_S_PS_AND_dS_PB, then_u_NM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule15); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule16 "IF S = PS AND dS = PM, THEN u = NM "
 FuzzyRuleAntecedent* if_S_PS_AND_dS_PM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PS_AND_dS_PM->joinWithAND( S_PS, dS_PM); // Adding corresponding FuzzySet to Antecedent object
 // Instantiating a FuzzyRule object
 FuzzyRule* fuzzyRule16 = new FuzzyRule(16, if_S_PS_AND_dS_PM, then_u_NM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule16); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule17 "IF S = PS AND dS = PS, THEN u = NS "
 FuzzyRuleAntecedent* if_S_PS_AND_dS_PS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PS_AND_dS_PS->joinWithAND( S_PS, dS_PS); // Adding corresponding FuzzySet to Antecedent object
 // Instantiating a FuzzyRule object
 FuzzyRule* fuzzyRule17 = new FuzzyRule(17, if_S_PS_AND_dS_PS, then_u_NS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule17); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule18 "IF S = PS AND dS = ZO, THEN u = NS "
 FuzzyRuleAntecedent* if_S_PS_AND_dS_ZO = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PS_AND_dS_ZO->joinWithAND( S_PS, dS_ZO); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule18 = new FuzzyRule(18, if_S_PS_AND_dS_ZO, then_u_NS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule18); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule19 "IF S = PS AND dS = NS, THEN u = ZO "
 FuzzyRuleAntecedent* if_S_PS_AND_dS_NS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PS_AND_dS_NS->joinWithAND( S_PS, dS_NS); // Adding corresponding FuzzySet to Antecedent object
 // Instantiating a FuzzyRule object
 FuzzyRule* fuzzyRule19 = new FuzzyRule(19, if_S_PS_AND_dS_NS, then_u_ZO); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule19); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule20 "IF S = PS AND dS = NM, THEN u = PS "
 FuzzyRuleAntecedent* if_S_PS_AND_dS_NM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PS_AND_dS_NM->joinWithAND( S_PS, dS_NM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule20 = new FuzzyRule(20, if_S_PS_AND_dS_NM, then_u_PS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule20); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule21 "IF S = PS AND dS = NB, THEN u = PS "
 FuzzyRuleAntecedent* if_S_PS_AND_dS_NB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_PS_AND_dS_NB->joinWithAND( S_PS, dS_NB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule21 = new FuzzyRule(21, if_S_PS_AND_dS_NB, then_u_PS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule21); // Adding FuzzyRule to Fuzzy object
 
//========================================================Rule 22-28 ============================================================================

 // FuzzyRule22 "IF S = ZO AND dS = PB, THEN u = NM "
 FuzzyRuleAntecedent* if_S_ZO_AND_dS_PB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_ZO_AND_dS_PB->joinWithAND( S_ZO, dS_PB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule22 = new FuzzyRule(22, if_S_ZO_AND_dS_PB, then_u_NM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule22); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule23 "IF S = ZO AND dS = PM, THEN u = NS "
 FuzzyRuleAntecedent* if_S_ZO_AND_dS_PM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_ZO_AND_dS_PM->joinWithAND( S_ZO, dS_PM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule23 = new FuzzyRule(23, if_S_ZO_AND_dS_PM, then_u_NS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule23); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule24 "IF S = ZO AND dS = PS, THEN u = NS "
 FuzzyRuleAntecedent* if_S_ZO_AND_dS_PS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_ZO_AND_dS_PS->joinWithAND( S_ZO, dS_PS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule24 = new FuzzyRule(24, if_S_ZO_AND_dS_PS, then_u_NS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule24); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule25 "IF S = ZO AND dS = ZO, THEN u = ZO "
 FuzzyRuleAntecedent* if_S_ZO_AND_dS_ZO = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_ZO_AND_dS_ZO->joinWithAND( S_ZO, dS_ZO); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule25 = new FuzzyRule(25, if_S_ZO_AND_dS_ZO, then_u_ZO); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule25); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule26 "IF S = ZO AND dS = NS, THEN u = PS "
 FuzzyRuleAntecedent* if_S_ZO_AND_dS_NS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_ZO_AND_dS_NS->joinWithAND( S_ZO, dS_NS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule26 = new FuzzyRule(26, if_S_ZO_AND_dS_NS, then_u_PS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule26); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule27 "IF S = ZO AND dS = NM, THEN u = PS "
 FuzzyRuleAntecedent* if_S_ZO_AND_dS_NM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_ZO_AND_dS_NM->joinWithAND( S_ZO, dS_NM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule27 = new FuzzyRule(27, if_S_ZO_AND_dS_NM, then_u_PS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule27); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule28 "IF S = ZO AND dS = NB, THEN u = PM "
 FuzzyRuleAntecedent* if_S_ZO_AND_dS_NB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_ZO_AND_dS_NB->joinWithAND( S_ZO, dS_NB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule28 = new FuzzyRule(28, if_S_ZO_AND_dS_NB, then_u_PM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule28); // Adding FuzzyRule to Fuzzy object
 
//========================================================Rule 29-35 ============================================================================

 // FuzzyRule29 "IF S = NS AND dS = PB, THEN u = NS "
 FuzzyRuleAntecedent* if_S_NS_AND_dS_PB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NS_AND_dS_PB->joinWithAND( S_NS, dS_PB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule29 = new FuzzyRule(29, if_S_NS_AND_dS_PB, then_u_NS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule29); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule30 "IF S = NS AND dS = PM, THEN u = NS "
 FuzzyRuleAntecedent* if_S_NS_AND_dS_PM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NS_AND_dS_PM->joinWithAND( S_NS, dS_PM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule30 = new FuzzyRule(30, if_S_NS_AND_dS_PM, then_u_NS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule30); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule31 "IF S = NS AND dS = PS, THEN u = ZO "
 FuzzyRuleAntecedent* if_S_NS_AND_dS_PS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NS_AND_dS_PS->joinWithAND( S_NS, dS_PS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule31 = new FuzzyRule(31, if_S_NS_AND_dS_PS, then_u_ZO); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule31); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule32 "IF S = NS AND dS = ZO, THEN u = PS "
 FuzzyRuleAntecedent* if_S_NS_AND_dS_ZO = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NS_AND_dS_ZO->joinWithAND( S_NS, dS_ZO); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule32 = new FuzzyRule(32, if_S_NS_AND_dS_ZO, then_u_PS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule32); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule33 "IF S = NS AND dS = NS, THEN u = PS "
 FuzzyRuleAntecedent* if_S_NS_AND_dS_NS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NS_AND_dS_NS->joinWithAND( S_NS, dS_NS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule33 = new FuzzyRule(33, if_S_NS_AND_dS_NS, then_u_PS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule33); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule34 "IF S = NS AND dS = NM, THEN u = PM "
 FuzzyRuleAntecedent* if_S_NS_AND_dS_NM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NS_AND_dS_NM->joinWithAND( S_NS, dS_NM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule34 = new FuzzyRule(34, if_S_NS_AND_dS_NM, then_u_PM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule34); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule35 "IF S = NS AND dS = NB, THEN u = PM "
 FuzzyRuleAntecedent* if_S_NS_AND_dS_NB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NS_AND_dS_NB->joinWithAND( S_NS, dS_NB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule35 = new FuzzyRule(35, if_S_NS_AND_dS_NB, then_u_PM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule35); // Adding FuzzyRule to Fuzzy object

//========================================================Rule 36-42 ============================================================================

 // FuzzyRule36 "IF S = NM AND dS = PB, THEN u = NS "
 FuzzyRuleAntecedent* if_S_NM_AND_dS_PB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NM_AND_dS_PB->joinWithAND( S_NM, dS_PB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule36 = new FuzzyRule(36, if_S_NM_AND_dS_PB, then_u_NS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule36); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule37 "IF S = NM AND dS = PM, THEN u = ZO "
 FuzzyRuleAntecedent* if_S_NM_AND_dS_PM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NM_AND_dS_PM->joinWithAND( S_NM, dS_PM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule37 = new FuzzyRule(37, if_S_NM_AND_dS_PM, then_u_ZO); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule37); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule38 "IF S = NM AND dS = PS, THEN u = PS "
 FuzzyRuleAntecedent* if_S_NM_AND_dS_PS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NM_AND_dS_PS->joinWithAND( S_NM, dS_PS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule38 = new FuzzyRule(38, if_S_NM_AND_dS_PS, then_u_PS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule38); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule39 "IF S = NM AND dS = ZO, THEN u = PS "
 FuzzyRuleAntecedent* if_S_NM_AND_dS_ZO = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NM_AND_dS_ZO->joinWithAND( S_NM, dS_ZO); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule39 = new FuzzyRule(39, if_S_NM_AND_dS_ZO, then_u_PS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule39); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule40 "IF S = NM AND dS = NS, THEN u = PM "
 FuzzyRuleAntecedent* if_S_NM_AND_dS_NS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NM_AND_dS_NS->joinWithAND( S_NM, dS_NS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule40 = new FuzzyRule(40, if_S_NM_AND_dS_NS, then_u_PM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule40); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule41 "IF S = NM AND dS = NM, THEN u = PM "
 FuzzyRuleAntecedent* if_S_NM_AND_dS_NM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NM_AND_dS_NM->joinWithAND( S_NM, dS_NM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule41 = new FuzzyRule(41, if_S_NM_AND_dS_NM, then_u_PM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule41); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule42 "IF S = NM AND dS = NB, THEN u = PB "
 FuzzyRuleAntecedent* if_S_NM_AND_dS_NB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NM_AND_dS_NB->joinWithAND( S_NM, dS_NB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule42 = new FuzzyRule(42, if_S_NM_AND_dS_NB, then_u_PB); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule42); // Adding FuzzyRule to Fuzzy object

 
//========================================================Rule 43-49 ============================================================================

 // FuzzyRule43 "IF S = NB AND dS = PB, THEN u = ZO "
 FuzzyRuleAntecedent* if_S_NB_AND_dS_PB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NB_AND_dS_PB->joinWithAND( S_NB, dS_PB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule43 = new FuzzyRule(43, if_S_NB_AND_dS_PB, then_u_ZO); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule43); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule44 "IF S = NB AND dS = PM, THEN u = PS "
 FuzzyRuleAntecedent* if_S_NB_AND_dS_PM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NB_AND_dS_PM->joinWithAND( S_NB, dS_PM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule44 = new FuzzyRule(44, if_S_NB_AND_dS_PM, then_u_PS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule44); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule45 "IF S = NB AND dS = PS, THEN u = PS "
 FuzzyRuleAntecedent* if_S_NB_AND_dS_PS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NB_AND_dS_PS->joinWithAND( S_NB, dS_PS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule45 = new FuzzyRule(45, if_S_NB_AND_dS_PS, then_u_PS); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule45); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule46 "IF S = NB AND dS = ZO, THEN u = PM "
 FuzzyRuleAntecedent* if_S_NB_AND_dS_ZO = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NB_AND_dS_ZO->joinWithAND( S_NB, dS_ZO); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule46 = new FuzzyRule(46, if_S_NB_AND_dS_ZO, then_u_PM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule46); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule47 "IF S = NB AND dS = NS, THEN u = PM "
 FuzzyRuleAntecedent* if_S_NB_AND_dS_NS = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NB_AND_dS_NS->joinWithAND( S_NB, dS_NS); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule47 = new FuzzyRule(47 ,if_S_NB_AND_dS_NS, then_u_PM); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule47); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule48 "IF S = NB AND dS = NM, THEN u = PB "
 FuzzyRuleAntecedent* if_S_NB_AND_dS_NM = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NB_AND_dS_NM->joinWithAND( S_NB, dS_NM); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule48 = new FuzzyRule(48, if_S_NB_AND_dS_NM, then_u_PB); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule48); // Adding FuzzyRule to Fuzzy object
 
  // FuzzyRule49 "IF S = NB AND dS = NB, THEN u = PB "
 FuzzyRuleAntecedent* if_S_NB_AND_dS_NB = new FuzzyRuleAntecedent(); // Instantiating an Antecedent to expression
 if_S_NB_AND_dS_NB->joinWithAND( S_NB, dS_NB); // Adding corresponding FuzzySet to Antecedent object
 FuzzyRule* fuzzyRule49 = new FuzzyRule(49, if_S_NB_AND_dS_NB, then_u_PB); // Passing the Antecedent and the Consequent of expression  
 Bikefuzzy->addFuzzyRule(fuzzyRule49); // Adding FuzzyRule to Fuzzy object

}


float fuzzy_calculate(double surface, double d_surface){
// Step 5 - Report inputs value, passing its ID and value
 Bikefuzzy->setInput(1, surface); 
 Bikefuzzy->setInput(2, d_surface); 
 // Step 6 - Exe the fuzzification
 Bikefuzzy->fuzzify(); 
 // Step 7 - Exe the desfuzzyfication for each output, passing its ID
 float output = Bikefuzzy->defuzzify(1);

 return output;

}


