/**
 * 
 */

#define Interface_Make_Body1(INTERFACE_NAME, TYPE1, FUNC1, ARG1) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1};\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 1, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body2(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 2, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body3(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2,\
                        TYPE3, FUNC3, ARG3 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 3, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body4(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2,\
                        TYPE3, FUNC3, ARG3, TYPE4, FUNC4, ARG4 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 4, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body5(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2,\
                        TYPE3, FUNC3, ARG3, TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 5, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body6(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2,\
                        TYPE3, FUNC3, ARG3, TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 6, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body7(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 7, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body8(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 8, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME }; 
	 
	 
#define Interface_Make_Body9(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 9, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };	 
	 
	 
#define Interface_Make_Body10(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 10, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };	 
	 
	 
#define Interface_Make_Body11(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10, TYPE11, FUNC11, ARG11 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10, #FUNC11 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10, &_interfaceVarRef##INTERFACE_NAME.FUNC11 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 11, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };	 


#define Interface_Make_Body12(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10, TYPE11, FUNC11, ARG11,\
                        TYPE12, FUNC12, ARG12 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10, #FUNC11, #FUNC12 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10, &_interfaceVarRef##INTERFACE_NAME.FUNC11,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC12 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 12, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body13(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10, TYPE11, FUNC11, ARG11,\
                        TYPE12, FUNC12, ARG12, TYPE13, FUNC13, ARG13 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10, #FUNC11, #FUNC12, #FUNC13 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10, &_interfaceVarRef##INTERFACE_NAME.FUNC11,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC12, &_interfaceVarRef##INTERFACE_NAME.FUNC13};\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 13, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body14(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10, TYPE11, FUNC11, ARG11,\
                        TYPE12, FUNC12, ARG12, TYPE13, FUNC13, ARG13, TYPE14, FUNC14, ARG14 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10, #FUNC11, #FUNC12, #FUNC13, #FUNC14 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10, &_interfaceVarRef##INTERFACE_NAME.FUNC11,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC12, &_interfaceVarRef##INTERFACE_NAME.FUNC13,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC14 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 14, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body15(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10, TYPE11, FUNC11, ARG11,\
                        TYPE12, FUNC12, ARG12, TYPE13, FUNC13, ARG13, TYPE14, FUNC14, ARG14, TYPE15, FUNC15, ARG15 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10, #FUNC11, #FUNC12, #FUNC13, #FUNC14, #FUNC15 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10, &_interfaceVarRef##INTERFACE_NAME.FUNC11,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC12, &_interfaceVarRef##INTERFACE_NAME.FUNC13,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC14, &_interfaceVarRef##INTERFACE_NAME.FUNC15 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 15, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body16(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10, TYPE11, FUNC11, ARG11,\
                        TYPE12, FUNC12, ARG12, TYPE13, FUNC13, ARG13, TYPE14, FUNC14, ARG14, TYPE15, FUNC15, ARG15,\
                        TYPE16, FUNC16, ARG16) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10, #FUNC11, #FUNC12, #FUNC13, #FUNC14, #FUNC15, #FUNC16 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10, &_interfaceVarRef##INTERFACE_NAME.FUNC11,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC12, &_interfaceVarRef##INTERFACE_NAME.FUNC13,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC14, &_interfaceVarRef##INTERFACE_NAME.FUNC15,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC16 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 16, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body17(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10, TYPE11, FUNC11, ARG11,\
                        TYPE12, FUNC12, ARG12, TYPE13, FUNC13, ARG13, TYPE14, FUNC14, ARG14, TYPE15, FUNC15, ARG15,\
                        TYPE16, FUNC16, ARG16, TYPE17, FUNC17, ARG17 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10, #FUNC11, #FUNC12, #FUNC13, #FUNC14, #FUNC15, #FUNC16, #FUNC17 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10, &_interfaceVarRef##INTERFACE_NAME.FUNC11,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC12, &_interfaceVarRef##INTERFACE_NAME.FUNC13,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC14, &_interfaceVarRef##INTERFACE_NAME.FUNC15,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC16, &_interfaceVarRef##INTERFACE_NAME.FUNC17 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 17, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body18(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10, TYPE11, FUNC11, ARG11,\
                        TYPE12, FUNC12, ARG12, TYPE13, FUNC13, ARG13, TYPE14, FUNC14, ARG14, TYPE15, FUNC15, ARG15,\
                        TYPE16, FUNC16, ARG16, TYPE17, FUNC17, ARG17, TYPE18, FUNC18, ARG18 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10, #FUNC11, #FUNC12, #FUNC13, #FUNC14, #FUNC15, #FUNC16, #FUNC17, #FUNC18 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10, &_interfaceVarRef##INTERFACE_NAME.FUNC11,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC12, &_interfaceVarRef##INTERFACE_NAME.FUNC13,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC14, &_interfaceVarRef##INTERFACE_NAME.FUNC15,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC16, &_interfaceVarRef##INTERFACE_NAME.FUNC17,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC18 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 18, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body19(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10, TYPE11, FUNC11, ARG11,\
                        TYPE12, FUNC12, ARG12, TYPE13, FUNC13, ARG13, TYPE14, FUNC14, ARG14, TYPE15, FUNC15, ARG15,\
                        TYPE16, FUNC16, ARG16, TYPE17, FUNC17, ARG17, TYPE18, FUNC18, ARG18, TYPE19, FUNC19, ARG19 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10, #FUNC11, #FUNC12, #FUNC13, #FUNC14, #FUNC15, #FUNC16, #FUNC17, #FUNC18, #FUNC19 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10, &_interfaceVarRef##INTERFACE_NAME.FUNC11,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC12, &_interfaceVarRef##INTERFACE_NAME.FUNC13,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC14, &_interfaceVarRef##INTERFACE_NAME.FUNC15,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC16, &_interfaceVarRef##INTERFACE_NAME.FUNC17,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC18, &_interfaceVarRef##INTERFACE_NAME.FUNC19 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 19, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body20(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10, TYPE11, FUNC11, ARG11,\
                        TYPE12, FUNC12, ARG12, TYPE13, FUNC13, ARG13, TYPE14, FUNC14, ARG14, TYPE15, FUNC15, ARG15,\
                        TYPE16, FUNC16, ARG16, TYPE17, FUNC17, ARG17, TYPE18, FUNC18, ARG18, TYPE19, FUNC19, ARG19,\
                        TYPE20, FUNC20, ARG20 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10, #FUNC11, #FUNC12, #FUNC13, #FUNC14, #FUNC15, #FUNC16, #FUNC17, #FUNC18, #FUNC19, #FUNC20 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10, &_interfaceVarRef##INTERFACE_NAME.FUNC11,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC12, &_interfaceVarRef##INTERFACE_NAME.FUNC13,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC14, &_interfaceVarRef##INTERFACE_NAME.FUNC15,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC16, &_interfaceVarRef##INTERFACE_NAME.FUNC17,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC18, &_interfaceVarRef##INTERFACE_NAME.FUNC19,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC20 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 20, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };


#define Interface_Make_Body21(INTERFACE_NAME, TYPE1, FUNC1, ARG1, TYPE2, FUNC2, ARG2, TYPE3, FUNC3, ARG3,\
                        TYPE4, FUNC4, ARG4, TYPE5, FUNC5, ARG5, TYPE6, FUNC6, ARG6, TYPE7, FUNC7, ARG7,\
                        TYPE8, FUNC8, ARG8, TYPE9, FUNC9, ARG9, TYPE10, FUNC10, ARG10, TYPE11, FUNC11, ARG11,\
                        TYPE12, FUNC12, ARG12, TYPE13, FUNC13, ARG13, TYPE14, FUNC14, ARG14, TYPE15, FUNC15, ARG15,\
                        TYPE16, FUNC16, ARG16, TYPE17, FUNC17, ARG17, TYPE18, FUNC18, ARG18, TYPE19, FUNC19, ARG19,\
                        TYPE20, FUNC20, ARG20, TYPE21, FUNC21, ARG21 ) \
	static char* InterfaceConfigFuncName_##INTERFACE_NAME[] = { #FUNC1, #FUNC2, #FUNC3, #FUNC4, #FUNC5, #FUNC6, #FUNC7, #FUNC8, #FUNC9, #FUNC10, #FUNC11, #FUNC12, #FUNC13, #FUNC14, #FUNC15, #FUNC16, #FUNC17, #FUNC18, #FUNC19, #FUNC20, #FUNC21 };\
	\
	static INTERFACE_NAME##_o _interfaceVarRef##INTERFACE_NAME;\
	\
	static void* _interfaceVarAddrRef##INTERFACE_NAME[] = {\
		&_interfaceVarRef##INTERFACE_NAME, &_interfaceVarRef##INTERFACE_NAME.FUNC1,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC2, &_interfaceVarRef##INTERFACE_NAME.FUNC3,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC4, &_interfaceVarRef##INTERFACE_NAME.FUNC5,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC6, &_interfaceVarRef##INTERFACE_NAME.FUNC7,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC8, &_interfaceVarRef##INTERFACE_NAME.FUNC9,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC10, &_interfaceVarRef##INTERFACE_NAME.FUNC11,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC12, &_interfaceVarRef##INTERFACE_NAME.FUNC13,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC14, &_interfaceVarRef##INTERFACE_NAME.FUNC15,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC16, &_interfaceVarRef##INTERFACE_NAME.FUNC17,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC18, &_interfaceVarRef##INTERFACE_NAME.FUNC19,\
		&_interfaceVarRef##INTERFACE_NAME.FUNC20, &_interfaceVarRef##INTERFACE_NAME.FUNC21 };\
	\
	interfaceConfig_t InterfaceConfig_##INTERFACE_NAME = {\
	 .func = (char**)InterfaceConfigFuncName_##INTERFACE_NAME,\
	 .numFunc = 21, ._sizeof = sizeof(INTERFACE_NAME##_o),\
	 .addr = (void**)_interfaceVarAddrRef##INTERFACE_NAME };

























































