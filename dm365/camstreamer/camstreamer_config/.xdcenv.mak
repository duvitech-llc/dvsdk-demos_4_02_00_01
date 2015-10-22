#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/dvsdk-demos_4_02_00_01/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/dmai_2_20_00_15/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/codec-engine_2_26_02_11/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/framework-components_2_26_00_01/packages;/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdais_6_26_01_03/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/linuxutils_2_26_01_02/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/codecs-dm365_4_02_00_00/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/codec-engine_2_26_02_11/examples
override XDCROOT = /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/dvsdk-demos_4_02_00_01/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/dmai_2_20_00_15/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/codec-engine_2_26_02_11/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/framework-components_2_26_00_01/packages;/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdais_6_26_01_03/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/linuxutils_2_26_01_02/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/codecs-dm365_4_02_00_00/packages;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/codec-engine_2_26_02_11/examples;/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages;..
HOSTOS = Linux
endif
