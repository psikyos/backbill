//#define USERNAME "ICASHER@T:GWHSRV8:ORCL"
//#define PASSWORD "ICASHER"
char sql_whole[]="SELECT PATIENT_ID,VISIT_ID,DEPT_CODE,\
		  WARD_CODE,BED_NO,\
		  TO_CHAR(BILLING_DATE_TIME,'YYYY-MM-DD:HH24:MI'), \
                  TO_CHAR(ADMISSION_DATE_TIME,'YYYY-MM-DD:HH24:MI') \
	   FROM   PATS_IN_HOSPITAL";

char sql_dept[]="SELECT PATIENT_ID,VISIT_ID,DEPT_CODE,\
		  WARD_CODE,BED_NO,\
		  TO_CHAR(BILLING_DATE_TIME,'YYYY-MM-DD:HH24:MI'), \
                  TO_CHAR(ADMISSION_DATE_TIME,'YYYY-MM-DD:HH24:MI') \
	   FROM   PATS_IN_HOSPITAL \
	   WHERE exists (select * from bill_dept_config \
	   					where dept_code=pats_in_hospital.dept_code)";

char sql_random[]="SELECT pats_in_hospital.patient_id,pats_in_hospital.visit_id,\
		  dept_code,ward_code,bed_no,\
                  TO_CHAR(pats_in_hospital.billing_date_time,'YYYY-MM-DD:HH24:MI'), \
                  TO_CHAR(need_billing_pats.billing_date_time,'YYYY-MM-DD:HH24:MI'), \
                  TO_CHAR(admission_date_time,'YYYY-MM-DD:HH24:MI') \
           FROM   need_billing_pats,pats_in_hospital \
           WHERE  billed_indicator=0 AND \
                  pats_in_hospital.patient_id=need_billing_pats.patient_id AND \
		  pats_in_hospital.visit_id=need_billing_pats.visit_id";

