################################################################################
# Automatically-generated file. Do not edit!
################################################################################

PROJ 	= TricoreTasking_TC377_BaseFrameWork
PRODDIR = D:\Tasking\ctc

-include "..\makefile.init"

all :

-include "subdir.mk"
-include "src\AppSw\Tricore\Cfg_Ssw\TC37A\subdir.mk"
-include "src\AppSw\Tricore\Demo_Irq\Adc_Irq\subdir.mk"
-include "src\AppSw\Tricore\Demo_Irq\Can_Irq\subdir.mk"
-include "src\AppSw\Tricore\Demo_Irq\Gpt12_Irq\subdir.mk"
-include "src\AppSw\Tricore\Demo_Irq\Gtm_Irq\subdir.mk"
-include "src\AppSw\Tricore\Demo_Irq\Spi_Irq\subdir.mk"
-include "src\AppSw\Tricore\Main\subdir.mk"
-include "src\BaseSw\EB_Cfg\src\subdir.mk"
-include "src\BaseSw\Infra\Autosar_Srv\subdir.mk"
-include "src\BaseSw\Infra\Integration\subdir.mk"
-include "src\BaseSw\Infra\Irq\ssc\src\subdir.mk"
-include "src\BaseSw\Infra\Ssw\TC37A\Tricore\subdir.mk"
-include "src\BaseSw\MCAL\Adc\ssc\src\subdir.mk"
-include "src\BaseSw\MCAL\Can_17_McmCan\ssc\src\subdir.mk"
-include "src\BaseSw\MCAL\Dio\ssc\src\subdir.mk"
-include "src\BaseSw\MCAL\McalLib\ssc\src\subdir.mk"
-include "src\BaseSw\MCAL\Mcu\ssc\src\subdir.mk"
-include "src\BaseSw\MCAL\Port\ssc\src\subdir.mk"
-include "src\BaseSw\MCAL\Pwm_17_GtmCcu6\ssc\src\subdir.mk"
-include "src\BaseSw\MCAL\Spi\ssc\src\subdir.mk"
-include "src\BaseSw\UserIf\subdir.mk"
-include "..\makefile.defs"

PCP_FILES :=
EXT_LIBRARIES =

all : "TricoreTasking_TC377_BaseFrameWork.elf"

"TricoreTasking_TC377_BaseFrameWork.elf" : $(OBJ_FILES) $(EXT_LIBRARIES) ".TricoreTasking_TC377_BaseFrameWork.elf.opt"
	@echo Linking to ${@F}
	@"${PRODDIR}\bin\cctc" -f ".TricoreTasking_TC377_BaseFrameWork.elf.opt"

".TricoreTasking_TC377_BaseFrameWork.elf.opt" : .refresh
	@argfile ".TricoreTasking_TC377_BaseFrameWork.elf.opt" -o "TricoreTasking_TC377_BaseFrameWork.elf" $(OBJ_FILES) $(EXT_LIBRARIES) $(PCP_FILES)  -Ctc37x --lsl-core=vtc -t -I"D:\desktop\TricoreTasking_TC377\TC377_Mcal_Test" -Wl-o"${PROJ}.hex":IHEX:4 --hex-format=s "..\src\ld\Lcf_Tasking_Tricore_Tc.lsl" -Wl-OtxycL -Wl--map-file="${PROJ}.mapxml":XML -Wl-mcrfiklSmNOduQ -Wl--error-limit=42 -g --fp-model=3 --c++=14 -Wl--dep-file=".TricoreTasking_TC377_BaseFrameWork.elf.d" -Wl--make-target="TricoreTasking_TC377_BaseFrameWork.elf"
DEPENDENCY_FILES += ".TricoreTasking_TC377_BaseFrameWork.elf.d"
-include $(DEPENDENCY_FILES)

$(EXT_LIBRARIES) : .dummy

GENERATED_FILES += "TricoreTasking_TC377_BaseFrameWork.elf" "TricoreTasking_TC377_BaseFrameWork*.sre" "TricoreTasking_TC377_BaseFrameWork*.hex" "TricoreTasking_TC377_BaseFrameWork.map*" "TricoreTasking_TC377_BaseFrameWork.mdf" ".TricoreTasking_TC377_BaseFrameWork.elf.opt" ".TricoreTasking_TC377_BaseFrameWork.elf.d"
-include "..\makefile.targets"


clean : ".clean.opt"
	@echo Cleaning
	@rm -f -m ".clean.opt"

".clean.opt" : .refresh
	@argfile ".clean.opt" $(GENERATED_FILES) $(OPTIONAL_FILES)

GENERATED_FILES += ".clean.opt"
OPTIONAL_FILES +=  "*.pre" "*.lst" "*.p.o" "*.p.a"


.PHONY : .dummy .refresh
