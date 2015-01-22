//---------------------------------------------------------------------------
//
//  Simple
//  
//  Basic UD U3 example for Dev-C++.  Demonstrates dynamic linking which
//  should work in many Windows compilers, if linking to labjackud.lib
//  (as shown in the VC6 examples) does not work.  Compared to the
//  normal C examples for VC6, the dynamic linking requires the
//  extra header file LJUD_DynamicLinking.h, and the LoadLabJackUD
//  function below.  The other change that must be made when converting
//  a VC6 example to dynamic linking, is to put "m_p" in front of all
//  the UD function names as seen in the code below.
//
//  So, to convert any of the VC6_LJUD examples (of which there are many)
//  to dynamic linking (for Dev-C, Borland, and others), do the following:
//
//  1.  Add an include for LJUD_DynamicLinking.h.
//
//  2.  Copy and paste the LoadLabJackUD function (below).
//
//  3.  Add "m_p" in front of all UD function names.
//
//
//  support@labjack.com
//  Sep 18, 2007
//----------------------------------------------------------------------
//

#include <stdio.h>
#include <windows.h>
#include "c:\program files\labjack\drivers\LabJackUD.h"
#include "..\..\LJUD_DynamicLinking.h"



//Start of LoadLabJackUD function.
//This is the function used to dynamically load the DLL.
void LoadLabJackUD (void)
{
    //Now try and load the DLL.
    if (hDLLInstance = LoadLibrary("labjackud.dll"))
    {  
        //If successfully loaded, get the address of the functions.
        m_pListAll = (tListAll)::GetProcAddress(hDLLInstance,"ListAll");
        m_pOpenLabJack = (tOpenLabJack)::GetProcAddress(hDLLInstance,"OpenLabJack");
        m_pAddRequest = (tAddRequest)::GetProcAddress(hDLLInstance,"AddRequest");
        m_pGo = (tGo)::GetProcAddress(hDLLInstance,"Go");
        m_pGoOne = (tGoOne)::GetProcAddress(hDLLInstance,"GoOne");
        m_peGet = (teGet)::GetProcAddress(hDLLInstance,"eGet");
        m_pePut = (tePut)::GetProcAddress(hDLLInstance,"ePut");
        m_pGetResult = (tGetResult)::GetProcAddress(hDLLInstance,"GetResult");
        m_pGetFirstResult = (tGetFirstResult)::GetProcAddress(hDLLInstance,"GetFirstResult");
        m_pGetNextResult = (tGetNextResult)::GetProcAddress(hDLLInstance,"GetNextResult");
        m_peAIN = (teAIN)::GetProcAddress(hDLLInstance,"eAIN");
        m_peDAC = (teDAC)::GetProcAddress(hDLLInstance,"eDAC");
        m_peDI = (teDI)::GetProcAddress(hDLLInstance,"eDI");
        m_peDO = (teDO)::GetProcAddress(hDLLInstance,"eDO");
        m_peAddGoGet = (teAddGoGet)::GetProcAddress(hDLLInstance,"eAddGoGet");
        m_peTCConfig = (teTCConfig)::GetProcAddress(hDLLInstance,"eTCConfig");
        m_peTCValues = (teTCValues)::GetProcAddress(hDLLInstance,"eTCValues");
        m_pResetLabJack = (tResetLabJack)::GetProcAddress(hDLLInstance,"ResetLabJack");
        m_pDoubleToStringAddress = (tDoubleToStringAddress)::GetProcAddress(hDLLInstance,"DoubleToStringAddress");
        m_pStringToDoubleAddress = (tStringToDoubleAddress)::GetProcAddress(hDLLInstance,"StringToDoubleAddress");
        m_pStringToConstant = (tStringToConstant)::GetProcAddress(hDLLInstance,"StringToConstant");
        m_pErrorToString = (tErrorToString)::GetProcAddress(hDLLInstance,"ErrorToString");
        m_pGetDriverVersion = (tGetDriverVersion)::GetProcAddress(hDLLInstance,"GetDriverVersion");
        m_pTCVoltsToTemp = (tTCVoltsToTemp)::GetProcAddress(hDLLInstance,"TCVoltsToTemp");
    }
    else
    {
        printf("\nFailed to load DLL\n");
        getchar();
        exit(0);
    }
     // m_pOpenLabJack now holds a pointer to the OpenLabJack function.  The compiler
     // automatically recognizes m_pOpenLabJack as a pointer to a function and
     // calls the function with the parameters given.  If we created another
     // variable of type tOpenLabJack and simply put "pNewVar = m_pOpenLabJack",
     // then the compiler might not know to call the function.
}
//End of LoadLabJackUD function.





//This is our simple error handling function that is called after every UD
//function call.  This function displays the errorcode and string description
//of the error.  It also has a line number input that can be used with the
//macro __LINE__ to display the line number in source code that called the
//error handler.  It also has an iteration input is useful when processing
//results in a loop (getfirst/getnext).
void ErrorHandler (LJ_ERROR lngErrorcode, long lngLineNumber, long lngIteration)
{
	char err[255];

	if (lngErrorcode != LJE_NOERROR)
	{
		m_pErrorToString(lngErrorcode,err);
		printf("Error number = %d\n",lngErrorcode);
		printf("Error string = %s\n",err);
		printf("Source line number = %d\n",lngLineNumber);
		printf("Iteration = %d\n\n",lngIteration);
		if(lngErrorcode > LJE_MIN_GROUP_ERROR)
		{
			//Quit if this is a group error.
			getchar();
			exit(0);
		}
   }
}





main()
{
	LJ_ERROR lngErrorcode;
	long lngGetNextIteration;
	double dblDriverVersion;
	long lngIOType=0, lngChannel=0;
	double dblValue=0;
	double Value2=9999,Value3=9999;
	double ValueDIBit=9999,ValueDIPort=9999,ValueCounter=9999;
	LJ_HANDLE lngHandle=0;
	char ch;
	
    //Load the DLL.
    LoadLabJackUD();

	//Read and display the UD version.
	dblDriverVersion = m_pGetDriverVersion();
	printf("UD Driver Version = %.3f\n\n",dblDriverVersion);


	//Open the first found LabJack U3.
	lngErrorcode = m_pOpenLabJack (LJ_dtU6, LJ_ctUSB, "1", 1, &lngHandle);
	ErrorHandler(lngErrorcode, __LINE__, 0);

	//Start by using the pin_configuration_reset IOType so that all
	//pin assignments are in the factory default condition.
	lngErrorcode = m_pePut (lngHandle, LJ_ioPIN_CONFIGURATION_RESET, 0, 0, 0);
	ErrorHandler(lngErrorcode, __LINE__, 0);


	//First some configuration commands.  These will be done with the ePut
	//function which combines the add/go/get into a single call.

	//Configure FIO2 and FIO3 as analog, all else as digital.  That means we
	//will start from channel 0 and update all 16 flexible bits.  We will
	//pass a value of b0000000000001100 or d12.
	lngErrorcode = m_pePut (lngHandle, LJ_ioPUT_ANALOG_ENABLE_PORT, 0, 12, 16);
	ErrorHandler(lngErrorcode, __LINE__, 0);

	//Set the timer/counter pin offset to 7, which will put the first
	//timer/counter on FIO7.
	lngErrorcode = m_pePut (lngHandle,  LJ_ioPUT_CONFIG, LJ_chTIMER_COUNTER_PIN_OFFSET, 7, 0);
	ErrorHandler(lngErrorcode, __LINE__, 0);

	//Enable Counter1 (FIO7).
	lngErrorcode = m_pePut (lngHandle,  LJ_ioPUT_COUNTER_ENABLE, 1, 1, 0);
	ErrorHandler(lngErrorcode, __LINE__, 0);


	//The following commands will use the add-go-get method to group
	//multiple requests into a single low-level function.
	//Request AIN2 and AIN3.
	lngErrorcode = m_pAddRequest (lngHandle, LJ_ioGET_AIN, 2, 0, 0, 0);
	ErrorHandler(lngErrorcode, __LINE__, 0);

	lngErrorcode = m_pAddRequest (lngHandle, LJ_ioGET_AIN, 3, 0, 0, 0);
	ErrorHandler(lngErrorcode, __LINE__, 0);

	//Set DAC0 to 2.5 volts.
	lngErrorcode = m_pAddRequest (lngHandle, LJ_ioPUT_DAC, 0, 2.5, 0, 0);
	ErrorHandler(lngErrorcode, __LINE__, 0);

	//Read digital input FIO0.
	lngErrorcode = m_pAddRequest (lngHandle, LJ_ioGET_DIGITAL_BIT, 0, 0, 0, 0);
	ErrorHandler(lngErrorcode, __LINE__, 0);

	//Set digital output FIO1 to output-high.
	lngErrorcode = m_pAddRequest (lngHandle, LJ_ioPUT_DIGITAL_BIT, 1, 1, 0, 0);
	ErrorHandler(lngErrorcode, __LINE__, 0);

	//Read digital inputs FIO4 through FIO6.
	lngErrorcode = m_pAddRequest (lngHandle, LJ_ioGET_DIGITAL_PORT, 4, 0, 3, 0);
	ErrorHandler(lngErrorcode, __LINE__, 0);

	//Request the value of Counter1.
	lngErrorcode = m_pAddRequest (lngHandle, LJ_ioGET_COUNTER, 1, 0, 0, 0);
	ErrorHandler(lngErrorcode, __LINE__, 0);


	while (1)
	{
	   //Execute the requests.
		lngErrorcode = m_pGoOne (lngHandle);
		ErrorHandler(lngErrorcode, __LINE__, 0);

	   	//Get all the results.  The input measurement results are stored.  All other
		//results are for configuration or output requests so we are just checking
		//whether there was an error.
		lngErrorcode = m_pGetFirstResult(lngHandle, &lngIOType, &lngChannel, &dblValue, 0, 0);
		ErrorHandler(lngErrorcode, __LINE__, 0);

		lngGetNextIteration=0;	//Used by the error handling function.

		while(lngErrorcode < LJE_MIN_GROUP_ERROR)
		{
			switch(lngIOType)
			{

			case LJ_ioGET_AIN :
				switch(lngChannel)
				{
					case 2:
						Value2=dblValue;
						break;
					case 3:
						Value3=dblValue;
						break;
				}
				break;

			case LJ_ioGET_DIGITAL_BIT :
				ValueDIBit=dblValue;
				break;

			case LJ_ioGET_DIGITAL_PORT :
				ValueDIPort=dblValue;
				break;

			case LJ_ioGET_COUNTER :
				ValueCounter=dblValue;
				break;

			}

			lngErrorcode = m_pGetNextResult(lngHandle, &lngIOType, &lngChannel, &dblValue, 0, 0);
			if(lngErrorcode != LJE_NO_MORE_DATA_AVAILABLE)
			{
				ErrorHandler(lngErrorcode, __LINE__, lngGetNextIteration);
			}

			lngGetNextIteration++;

		}

		printf("AIN2 = %f\n",Value2);
  		printf("AIN3 = %f\n",Value3);
		printf("FIO0 = %f\n",ValueDIBit);
		printf("FIO4-FIO6 = %f\n",ValueDIPort);  //Will read 7 if all 3 lines are pulled-high as normal.
		printf("Counter1 (FIO7) = %f\n",ValueCounter);

		printf("\nPress Enter to go again or (q) to quit\n");
		ch = getchar();
		if (ch == 'q') return 0;
	}


}
