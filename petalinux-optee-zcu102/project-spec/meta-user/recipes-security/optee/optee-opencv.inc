SUMMARY = "OP-TEE opencv"
DESCRIPTION = "Open Portable Trusted Execution Environment - Sample Applications"
HOMEPAGE = "https://github.com/linaro-swg/optee_examples"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

DEPENDS = "optee-client optee-os python3-pycryptodome-native opencv"

OPENCV_PACKAGES = " \
	opencv \
	libopencv-core \
	libopencv-highgui \
	libopencv-imgproc \
	libopencv-objdetect \
	libopencv-ml \
	libopencv-calib3d \
	libopencv-ccalib \
	"

RDEPENDS_${PN} = "${OPENCV_PACKAGES}"
inherit python3native

require optee.inc

FILESEXTRAPATHS_prepend := "/home/celeste/petalinux-optee:"
SRC_URI = "file://optee_opencv \
          "

EXTRA_OEMAKE += "TA_DEV_KIT_DIR=${TA_DEV_KIT_DIR} \
                 HOST_CROSS_COMPILE=${HOST_PREFIX} \
                 TA_CROSS_COMPILE=${HOST_PREFIX} \
                 OUTPUT_DIR=${B} \
               "

S = "${WORKDIR}/optee_opencv"
B = "${WORKDIR}/optee_opencv/out"

do_compile() {
    oe_runmake -C ${S}
}
do_compile[cleandirs] = "${B}"

do_install () {
    mkdir -p ${D}${nonarch_base_libdir}/optee_armtz
    mkdir -p ${D}${bindir}
    mkdir -p ${D}${libdir}/tee-supplicant/plugins
    install -D -p -m0755 ${B}/ca/* ${D}${bindir}
    install -D -p -m0444 ${B}/ta/* ${D}${nonarch_base_libdir}/optee_armtz
}
TARGET_CC_ARCH += "${LDFLAGS}"

FILES_${PN} += "${nonarch_base_libdir}/optee_armtz/ \
                ${libdir}/tee-supplicant/plugins/ \
               "

# Imports machine specific configs from staging to build
PACKAGE_ARCH = "${MACHINE_ARCH}"
