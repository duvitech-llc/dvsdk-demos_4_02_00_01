#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
override PKGDIR = encodedecode_config
XDCINCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(XPKGPATH))))
XDCCFGDIR = package/cfg/

#
# The following dependencies ensure package.mak is rebuilt
# in the event that some included BOM script changes.
#
ifneq (clean,$(MAKECMDGOALS))
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/arm/GCArmv6.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/arm/GCArmv6.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/services/io/File.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/services/io/File.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/_gen.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/_gen.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/dvsdk-demos_4_02_00_01/config.bld:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/dvsdk-demos_4_02_00_01/config.bld
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/tools/configuro/template/package.xs.xdt:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/tools/configuro/template/package.xs.xdt
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/services/io/package.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/services/io/package.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/PackageContents.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/PackageContents.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/xmlgen.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/xmlgen.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/Library.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/Library.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/tools/configuro/template/compiler.opt.xdt:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/tools/configuro/template/compiler.opt.xdt
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/ti/targets/ITarget.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/ti/targets/ITarget.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/Script.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/Script.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/xmlgen2.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/xmlgen2.xs
package.mak: package.bld
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/ti/targets/package.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/ti/targets/package.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/package.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/package.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/ITarget.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/ITarget.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/xdc.tci:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/xdc.tci
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/Executable.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/Executable.xs
package.mak: config.bld
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/IPackage.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/IPackage.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/MVArm9.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/MVArm9.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/tools/configuro/template/custom.mak.exe.xdt:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/tools/configuro/template/custom.mak.exe.xdt
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/om2.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/om2.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/include/utils.tci:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/include/utils.tci
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/UCArm9.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/UCArm9.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/services/global/Clock.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/services/global/Clock.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/ti/targets/MSP430_large_code.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/ti/targets/MSP430_large_code.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/Utils.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/Utils.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/Repository.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/Repository.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/ti/targets/MSP430.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/ti/targets/MSP430.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/Linux86.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/Linux86.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/Mingw.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/Mingw.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/template.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/template.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/arm/GCArmv7A.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/arm/GCArmv7A.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/ITargetFilter.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/ITargetFilter.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/ti/targets/MSP430_large_data.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/ti/targets/MSP430_large_data.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/services/global/Trace.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/services/global/Trace.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/ITarget.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/ITarget.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/package.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/package.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/BuildEnvironment.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/bld/BuildEnvironment.xs
/home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/package.xs:
package.mak: /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/xdc/package.xs
endif

gnu.targets.arm.GCArmv5T.rootDir ?= /opt/arm-2009q1/
gnu.targets.arm.packageBase ?= /home/gvigelet/ti-dvsdk_dm368-evm_4_02_00_06/xdctools_3_16_03_36/packages/gnu/targets/arm/
.PRECIOUS: $(XDCCFGDIR)/%.ov5T
.PHONY: all,v5T .dlls,v5T .executables,v5T test,v5T
all,v5T: .executables,v5T
.executables,v5T: .libraries,v5T
.executables,v5T: .dlls,v5T
.dlls,v5T: .libraries,v5T
.libraries,v5T: .interfaces
	@$(RM) $@
	@$(TOUCH) "$@"

.help::
	@$(ECHO) xdc test,v5T
	@$(ECHO) xdc .executables,v5T
	@$(ECHO) xdc .libraries,v5T
	@$(ECHO) xdc .dlls,v5T


all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.inc package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.inc package/%_encodedecode_config.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package encodedecode_config" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

.executables,v5T .executables: encodedecode.xv5T

-include package/cfg/encodedecode_xv5T.mak
ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/encodedecode_xv5T.dep
endif
package/cfg/encodedecode_xv5T.ov5T : | package/cfg/encodedecode_xv5T.xdl
encodedecode.xv5T:
	$(RM) $@
	@$(MSG) lnkv5T $@ ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-gcc    -o $@ package/cfg/encodedecode_xv5T.ov5T  package/cfg/encodedecode_xv5T.xdl  -lstdc++ -L$(gnu.targets.arm.GCArmv5T.rootDir)/arm-none-linux-gnueabi/lib
	
encodedecode.xv5T:LD_LIBRARY_PATH=


ifeq (,$(wildcard .libraries,v5T))
encodedecode.xv5T package/cfg/encodedecode_xv5T.c: .libraries,v5T
endif

package/cfg/encodedecode_xv5T.c package/cfg/encodedecode_xv5T.h package/cfg/encodedecode_xv5T.xdl: override _PROG_NAME := encodedecode.xv5T
package/cfg/encodedecode_xv5T.c: package/cfg/encodedecode_xv5T.cfg
encodedecode.test test,v5T test: encodedecode.xv5T.test

encodedecode.xv5T.test:: encodedecode.xv5T
ifeq (,$(_TESTLEVEL))
	@$(MAKE) -R -r --no-print-directory -f $(XDCROOT)/packages/xdc/bld/xdc.mak _TESTLEVEL=1 encodedecode.xv5T.test
else
	@$(MSG) running $<  ...
	$(call EXEC.encodedecode.xv5T, ) 
endif


clean:: clean,v5T
	-$(RM) package/cfg/encodedecode_xv5T.cfg
	-$(RM) package/cfg/encodedecode_xv5T.dep
	-$(RM) package/cfg/encodedecode_xv5T.c
	-$(RM) package/cfg/encodedecode_xv5T.xdc.inc

clean,v5T::
	-$(RM) encodedecode.xv5T
	-$(RM) .tmp,encodedecode.xv5T,*

%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@
encodedecode_xv5T.ov5T,copy : package/cfg/encodedecode_xv5T.ov5T
encodedecode_xv5T.sv5T,copy : package/cfg/encodedecode_xv5T.sv5T

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,encodedecode_config
encodedecode_config.tar: package/build.cfg
encodedecode_config.tar: package/package.ext.xml
encodedecode_config.tar: package/package.xdc.inc
encodedecode_config.tar: package/package.bld.xml
encodedecode_config.tar: package/package.rel.dot
ifneq (clean,$(MAKECMDGOALS))
-include package/rel/encodedecode_config.tar.dep
endif
package/rel/encodedecode_config/encodedecode_config/package/package.rel.xml:

encodedecode_config.tar: package/rel/encodedecode_config.xdc.inc package/rel/encodedecode_config/encodedecode_config/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELTAR,package/rel/encodedecode_config.xdc.inc,package/rel/encodedecode_config.tar.dep)


release release,encodedecode_config: all encodedecode_config.tar
clean:: .clean
	-$(RM) encodedecode_config.tar
	-$(RM) package/rel/encodedecode_config.xdc.inc
	-$(RM) package/rel/encodedecode_config.tar.dep

clean:: .clean
	-$(RM) .libraries .libraries,*
clean:: 
	-$(RM) .dlls .dlls,*
#
# The following clean rule removes user specified
# generated files or directories.
#

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(wildcard package))
    $(shell $(MKDIR) package)
endif
ifeq (,$(wildcard package/external))
    $(shell $(MKDIR) package/external)
endif
ifeq (,$(wildcard package/lib))
    $(shell $(MKDIR) package/lib)
endif
ifeq (,$(wildcard package/cfg))
    $(shell $(MKDIR) package/cfg)
endif
ifeq (,$(wildcard package/rel))
    $(shell $(MKDIR) package/rel)
endif
ifeq (,$(wildcard package/internal))
    $(shell $(MKDIR) package/internal)
endif
endif
clean::
	-$(RMDIR) package

include custom.mak
