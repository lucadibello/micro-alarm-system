#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/micro-alarm-system.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/micro-alarm-system.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=UART.c main.c MenuHandler.c PasswordManager.c RGB.c SecuritySystem.c Logger.c Speaker.c I2C.c Accelerometer.c Timer.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/UART.o ${OBJECTDIR}/main.o ${OBJECTDIR}/MenuHandler.o ${OBJECTDIR}/PasswordManager.o ${OBJECTDIR}/RGB.o ${OBJECTDIR}/SecuritySystem.o ${OBJECTDIR}/Logger.o ${OBJECTDIR}/Speaker.o ${OBJECTDIR}/I2C.o ${OBJECTDIR}/Accelerometer.o ${OBJECTDIR}/Timer.o
POSSIBLE_DEPFILES=${OBJECTDIR}/UART.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/MenuHandler.o.d ${OBJECTDIR}/PasswordManager.o.d ${OBJECTDIR}/RGB.o.d ${OBJECTDIR}/SecuritySystem.o.d ${OBJECTDIR}/Logger.o.d ${OBJECTDIR}/Speaker.o.d ${OBJECTDIR}/I2C.o.d ${OBJECTDIR}/Accelerometer.o.d ${OBJECTDIR}/Timer.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/UART.o ${OBJECTDIR}/main.o ${OBJECTDIR}/MenuHandler.o ${OBJECTDIR}/PasswordManager.o ${OBJECTDIR}/RGB.o ${OBJECTDIR}/SecuritySystem.o ${OBJECTDIR}/Logger.o ${OBJECTDIR}/Speaker.o ${OBJECTDIR}/I2C.o ${OBJECTDIR}/Accelerometer.o ${OBJECTDIR}/Timer.o

# Source Files
SOURCEFILES=UART.c main.c MenuHandler.c PasswordManager.c RGB.c SecuritySystem.c Logger.c Speaker.c I2C.c Accelerometer.c Timer.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/micro-alarm-system.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX370F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/UART.o: UART.c  .generated_files/flags/default/7c0bfd27de3e26c37a9f321a054ad574e0c15989 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/UART.o.d" -o ${OBJECTDIR}/UART.o UART.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/fa74d6a31b8d0906ae23e5ae364a4d68d86ea9e8 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/MenuHandler.o: MenuHandler.c  .generated_files/flags/default/a682d40f27d7b7a09421358d8bada93a22503e14 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MenuHandler.o.d 
	@${RM} ${OBJECTDIR}/MenuHandler.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/MenuHandler.o.d" -o ${OBJECTDIR}/MenuHandler.o MenuHandler.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/PasswordManager.o: PasswordManager.c  .generated_files/flags/default/792a97ad732c90513abe07534878c848c35ebcb .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PasswordManager.o.d 
	@${RM} ${OBJECTDIR}/PasswordManager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/PasswordManager.o.d" -o ${OBJECTDIR}/PasswordManager.o PasswordManager.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/RGB.o: RGB.c  .generated_files/flags/default/a32d12893269c4d22548f0d1d5f87679ec1f57c2 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RGB.o.d 
	@${RM} ${OBJECTDIR}/RGB.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/RGB.o.d" -o ${OBJECTDIR}/RGB.o RGB.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/SecuritySystem.o: SecuritySystem.c  .generated_files/flags/default/24d1647c1e2a7240d8e85c97ff3982d71aa454b3 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SecuritySystem.o.d 
	@${RM} ${OBJECTDIR}/SecuritySystem.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/SecuritySystem.o.d" -o ${OBJECTDIR}/SecuritySystem.o SecuritySystem.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Logger.o: Logger.c  .generated_files/flags/default/ff0e05fc6b16aded2aa7aa203f24fd8cf8eb4e3a .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Logger.o.d 
	@${RM} ${OBJECTDIR}/Logger.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Logger.o.d" -o ${OBJECTDIR}/Logger.o Logger.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Speaker.o: Speaker.c  .generated_files/flags/default/3e0d6c002198aedea3c856624c42eba12551254b .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Speaker.o.d 
	@${RM} ${OBJECTDIR}/Speaker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Speaker.o.d" -o ${OBJECTDIR}/Speaker.o Speaker.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/I2C.o: I2C.c  .generated_files/flags/default/8a53a78b3c45a520d2d7204fbb604530027e7ef2 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/I2C.o.d 
	@${RM} ${OBJECTDIR}/I2C.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/I2C.o.d" -o ${OBJECTDIR}/I2C.o I2C.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Accelerometer.o: Accelerometer.c  .generated_files/flags/default/a8fdd67e6f4572e6a2b3593040988533e151f73d .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Accelerometer.o.d 
	@${RM} ${OBJECTDIR}/Accelerometer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Accelerometer.o.d" -o ${OBJECTDIR}/Accelerometer.o Accelerometer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Timer.o: Timer.c  .generated_files/flags/default/57165212c15f4c72c4cc2abe44598a23af760142 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timer.o.d 
	@${RM} ${OBJECTDIR}/Timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Timer.o.d" -o ${OBJECTDIR}/Timer.o Timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/UART.o: UART.c  .generated_files/flags/default/4c330aa5413725b7a4196e00dfff5be045d20e3e .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART.o.d 
	@${RM} ${OBJECTDIR}/UART.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/UART.o.d" -o ${OBJECTDIR}/UART.o UART.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/a0ac124b8e521a9ad5f4b2e3700767e1cb2c8637 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/MenuHandler.o: MenuHandler.c  .generated_files/flags/default/50afe423320acb4a34bfeaa95cde22bdf8d63180 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MenuHandler.o.d 
	@${RM} ${OBJECTDIR}/MenuHandler.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/MenuHandler.o.d" -o ${OBJECTDIR}/MenuHandler.o MenuHandler.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/PasswordManager.o: PasswordManager.c  .generated_files/flags/default/5c6821ee863bd8c3ee739924ef42e158be345dc5 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/PasswordManager.o.d 
	@${RM} ${OBJECTDIR}/PasswordManager.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/PasswordManager.o.d" -o ${OBJECTDIR}/PasswordManager.o PasswordManager.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/RGB.o: RGB.c  .generated_files/flags/default/b2f649de7ef97be083e7c8aa315e4299cc735711 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/RGB.o.d 
	@${RM} ${OBJECTDIR}/RGB.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/RGB.o.d" -o ${OBJECTDIR}/RGB.o RGB.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/SecuritySystem.o: SecuritySystem.c  .generated_files/flags/default/53346cdaf76fa535c6776cd1514a5e908f40ba93 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/SecuritySystem.o.d 
	@${RM} ${OBJECTDIR}/SecuritySystem.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/SecuritySystem.o.d" -o ${OBJECTDIR}/SecuritySystem.o SecuritySystem.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Logger.o: Logger.c  .generated_files/flags/default/5da1c354de835459a8123fcd845f6f2429860ef3 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Logger.o.d 
	@${RM} ${OBJECTDIR}/Logger.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Logger.o.d" -o ${OBJECTDIR}/Logger.o Logger.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Speaker.o: Speaker.c  .generated_files/flags/default/ce46c6533fd5fe9e857001e767424577ba1257a9 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Speaker.o.d 
	@${RM} ${OBJECTDIR}/Speaker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Speaker.o.d" -o ${OBJECTDIR}/Speaker.o Speaker.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/I2C.o: I2C.c  .generated_files/flags/default/cbd74b2de32733a5a466b3be516441ed5823f7fb .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/I2C.o.d 
	@${RM} ${OBJECTDIR}/I2C.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/I2C.o.d" -o ${OBJECTDIR}/I2C.o I2C.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Accelerometer.o: Accelerometer.c  .generated_files/flags/default/997364e031cac4074409869494720e67c5ac6eea .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Accelerometer.o.d 
	@${RM} ${OBJECTDIR}/Accelerometer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Accelerometer.o.d" -o ${OBJECTDIR}/Accelerometer.o Accelerometer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Timer.o: Timer.c  .generated_files/flags/default/34c195b8651b84bc1f232ab41173713b9dd93946 .generated_files/flags/default/115e56875758b112e91d6b9813d23d9838dcc952
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Timer.o.d 
	@${RM} ${OBJECTDIR}/Timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Timer.o.d" -o ${OBJECTDIR}/Timer.o Timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/micro-alarm-system.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/micro-alarm-system.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC0275F  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=512,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/micro-alarm-system.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/micro-alarm-system.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=512,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/micro-alarm-system.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
