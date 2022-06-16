SRC_URI += "file://bsp.cfg"
KERNEL_FEATURES_append = " bsp.cfg"
FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI_append += "file://kernel_optee.cfg"
