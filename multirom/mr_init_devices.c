#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
    // FrameBuffers
    "/sys/class/graphics/fb0",

    // Storage devices
    "/sys/dev/block*",
    "/sys/block/mmcblk0",
    "/sys/module/mmc_core",
    "/sys/module/mmcblk",

    // Internal storage
    "/sys/block/mmcblk0rpmb",
    "/dev/block/bootdevice/by-name/*",
    "/sys/devices/soc/7464900.sdhci",
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0",
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001",
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0",
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/*",
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p16", // boot
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p17", // keymaster
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p23", // modem
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p33", // modemst1
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p34", // modemst2
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p35", // cache
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p36", // persist
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p32", // ssd
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p55", // system
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p54", // userdata
    "/sys/devices/soc/7464900.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0rpmb", // RPMB

    // External storage
    "/sys/block/mmcblk1",
    "/sys/block/mmcblk1",
    "/sys/block/mmcblk1/mmcblk1p1",
    "/sys/block/mmcblk1/mmcblk1p2",

    // Devices
    "/sys/bus*",
    "/sys/bus/mmc",
    "/sys/bus/mmc/drivers/mmcblk",
    "/sys/devices*",
    "/sys/devices/virtual/mem/null",
    "/sys/devices/virtual/misc/fuse",

    // Inputs
    "/sys/class/input/event*",
    "/sys/class/input/input*",
    "/sys/class/misc/uinput",
    "/sys/class/tty/ptmx",
    "/sys/devices/soc/soc:gpio_keys/input*",
    "/sys/devices/virtual/input*",
    "/sys/devices/virtual/misc/uinput",
    "/sys/devices/soc/75ba000.i2c/i2c-12/12-002c/clearpad",

    // ADB
    "/sys/devices/virtual/tty/ptmx",
    "/sys/bus/usb",
    "/sys/bus/usb-serial",
    "/sys/class/android_usb/android0/f_adb",
    "/sys/class/misc/android_adb",
    "/sys/devices/virtual/misc/mtp_usb",

    // USB
    "/sys/bus/usb",
    "/sys/bus/platform/drivers/xhci-hcd*",
    "/sys/devices/soc/6a00000.ssusb/6a00000.dwc3",

    // USB test
    "/sys/bus/usb"
    "/sys/bus/usb/drivers/usb"
    "/sys/bus/usb/drivers/usbfs"
    "/sys/bus/usb/drivers/usb-storage"
    "/sys/bus/usb/drivers/usb_ehset_test"
    "/sys/bus/usb/drivers/usbserial"
    "/sys/bus/usb/drivers/usbhid"
    "/sys/bus/usb/drivers/snd-usb-audio"
    "/sys/bus/usb-serial"
    "/sys/bus/platform/devices/6b04000.qcom,usbbam"
    "/sys/bus/platform/devices/6a00000.ssusb"
    "/sys/bus/platform/devices/7412000.qusb"
    "/sys/bus/platform/devices/soc:usb_nop_phy"
    "/sys/bus/platform/devices/66bf0c8.android_usb"
    "/sys/bus/platform/devices/7411000.qusb"
    "/sys/bus/platform/devices/soc:usb-otg-switch"
    "/sys/bus/platform/drivers/msm-qusb-phy"
    "/sys/bus/platform/drivers/msm-qusb-phy/7411000.qusb"
    "/sys/bus/platform/drivers/reg-fixed-voltage/soc:usb-otg-switch"
    "/sys/bus/platform/drivers/android_usb"
    "/sys/bus/platform/drivers/android_usb/66bf0c8.android_usb"
    "/sys/bus/platform/drivers/msm-usb-ssphy-qmp"
    "/sys/bus/platform/drivers/usb_bam"
    "/sys/bus/platform/drivers/usb_bam/6b04000.qcom,usbbam"
    "/sys/bus/platform/drivers/msm-dwc3/6a00000.ssusb"
    "/sys/bus/platform/drivers/msm-usb-dbm"
    "/sys/bus/msm-bus-type/devices/mas-usb3"
    "/sys/bus/msm-bus-type/devices/slv-usb-hs"
    "/sys/bus/msm-bus-type/devices/slv-usb3"
    "/sys/bus/msm-bus-type/devices/mas-usb-hs"
    "/sys/devices/soc/qpnp-smbcharger-16/usb_max_current"
    "/sys/devices/soc/qpnp-smbcharger-16/usb_cmd_il"
    "/sys/devices/soc/qpnp-smbcharger-16/usb_rid_sts"
    "/sys/devices/soc/qpnp-smbcharger-16/usb_usbin_il_cfg"
    "/sys/devices/soc/qpnp-smbcharger-16/usb_voter"
    "/sys/devices/soc/qpnp-smbcharger-16/usb_online"
    "/sys/devices/soc/qpnp-smbcharger-16/usbin_voter"
    "/sys/devices/soc/qpnp-smbcharger-16/therm_miti_usb5v"
    "/sys/devices/soc/qpnp-smbcharger-16/therm_miti_usb6v"
    "/sys/devices/soc/qpnp-smbcharger-16/therm_miti_usb7v"
    "/sys/devices/soc/qpnp-smbcharger-16/therm_miti_usb8v"
    "/sys/devices/soc/qpnp-smbcharger-16/therm_miti_usb9v"
    "/sys/devices/soc/qpnp-smbcharger-16/usb_int"
    "/sys/devices/soc/qpnp-smbcharger-16/usb_icl_sts"
    "/sys/devices/soc/qpnp-smbcharger-16/limit_usb5v_level"
    "/sys/devices/soc/qpnp-smbcharger-16/usb_apsd_dg"
    "/sys/devices/soc/qpnp-smbcharger-16/usb_hvdcp_sts"
    "/sys/devices/soc/qpnp-smbcharger-16/usb_present"
    "/sys/devices/soc/30f004.qcom,gdsc/regulator/regulator.84/6a00000.ssusb-USB3_GDSC"
    "/sys/devices/soc/6a00000.ssusb"
    "/sys/devices/soc/6a00000.ssusb/6b04000.qcom,usbbam"
    "/sys/devices/soc/6a00000.ssusb/power_supply/usb"
    "/sys/devices/soc/6a00000.ssusb/power_supply/usb/usb_otg"
    "/sys/devices/soc/7412000.qusb"
    "/sys/devices/soc/qpnp-fg-17/usb_ibat_max"
    "/sys/devices/soc/soc:usb_nop_phy"
    "/sys/devices/soc/qpnp-vadc-15/usbin"
    "/sys/devices/soc/qpnp-vadc-15/usb_dm"
    "/sys/devices/soc/qpnp-vadc-15/usb_dp"
    "/sys/devices/soc/soc:qcom,rpm-smd/soc:qcom,rpm-smd:rpm-regulator-smpa2/soc:qcom,rpm-smd:rpm-regulator-smpa2:regulator-s2-corner/regulator/regulator.13/7411000.qusb-vdd"
    "/sys/devices/soc/soc:qcom,rpm-smd/soc:qcom,rpm-smd:rpm-regulator-ldoa12/soc:qcom,rpm-smd:rpm-regulator-ldoa12:regulator-l12/regulator/regulator.26/7411000.qusb-vdda18"
    "/sys/devices/soc/soc:qcom,rpm-smd/soc:qcom,rpm-smd:rpm-regulator-ldoa24/soc:qcom,rpm-smd:rpm-regulator-ldoa24:regulator-l24/regulator/regulator.38/7411000.qusb-vdda33"
    "/sys/devices/soc/66bf0c8.android_usb"
    "/sys/devices/soc/qpnp-vadc-5/usb_id_lv"
    "/sys/devices/soc/7411000.qusb"
    "/sys/devices/soc/soc:usb-otg-switch"
    "/sys/devices/mas-usb3"
    "/sys/devices/slv-usb-hs"
    "/sys/devices/slv-usb3"
    "/sys/devices/virtual/misc/usb_mirrorlink"
    "/sys/devices/virtual/misc/usb_accessory"
    "/sys/devices/virtual/misc/mtp_usb"
    "/sys/devices/virtual/msm_usb_bridge"
    "/sys/devices/virtual/msm_usb_bridge/at_usb0"
    "/sys/devices/virtual/msm_usb_bridge/at_usb1"
    "/sys/devices/virtual/android_usb"
    "/sys/devices/virtual/android_usb/android0/f_usb_mbim"
    "/sys/devices/virtual/usb_host_ext_event"
    "/sys/devices/virtual/usb_host_ext_event/usb_host_ext_event"
    "/sys/devices/platform/reg-dummy/regulator/regulator.0/7411000.qusb-USB3_GDSC"
    "/sys/devices/mas-usb-hs"

    // Encryption
    "/sys/devices/virtual/icesdcc/icesdcc",
    "/sys/devices/virtual/misc/device-mapper",
    "/sys/devices/virtual/misc/ion",
    "/sys/devices/virtual/qseecom/qseecom",

    // Logging
    "/sys/devices/virtual/mem/kmsg",

    NULL
};
