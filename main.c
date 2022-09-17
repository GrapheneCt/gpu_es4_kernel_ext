#include <kernel.h>
#include <taihen.h>

int module_start(SceSize args, const void * argp)
{
	tai_module_info_t info;
	info.size = sizeof(tai_module_info_t);
	if (taiGetModuleInfoForKernel(KERNEL_PID, "SceGpuEs4", &info) < 0)
		return SCE_KERNEL_START_SUCCESS;

	// Sync object
	taiInjectDataForKernel(KERNEL_PID, info.modid, 0, 0x184a, "\x00\x22", 2);
	// RT
	taiInjectDataForKernel(KERNEL_PID, info.modid, 0, 0x36c, "\x0A\xE0", 2);

	return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize args, const void * argp)
{
	return SCE_KERNEL_STOP_SUCCESS;
}