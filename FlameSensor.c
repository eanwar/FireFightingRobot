
void EnableFlameSensor(void){
	
	ReadFlameValues();
	DetectMaxFlameValue();
	GetThresholdValue();
}

void ReadFlameValues(void){
	uint8_t i;
	for (i=0;i<=num_of_sensors-1;i++)
	{
		FlameReads[i]=ADC_read(i+1);
		
	}
}


void DetectMaxFlameValue(void){
     
	 
	 uint8_t i;
	 MaxRead=FlameReads[0];
     for(i = 1; i <= NumOfSensors-1; i++)
     {
	     if(MaxRead < FlameReads[i])
	     {
		     MaxRead = FlameReads[i];
	     }
     }

}	


void GetThresholdValue(uint16_t Accuracy){
	uint8_t i;
	uint16_t Max;
	uint16_t MaxArray[Accuracy];
	
	for(i=0;i<=Accuracy-1;i++)
	{
		ReadFlameValues();
		Max[i]=DetectMaxFlameValue();
	}
	
	Threshold=FlameReads[0];
	for(i = 1; i <= Accuracy-1; i++)
	{
		if(Threshold < FlameReads[i])
		{
			Threshold = FlameReads[i];
		}
	}
	
	
}

uint16_t BeginScanning(void){
	
	EnableFlameSensor();
	Rotate();
	
}

