#ifndef __volume_h
#define __volume_h

#ifdef HAVE_ALSA
#include <alsa/asoundlib.h>
#endif

#include <lib/base/ebase.h>
#include <lib/base/nconfig.h>

class eDVBVolumecontrol
{
private:
#ifdef HAVE_ALSA
	snd_mixer_elem_t *mainVolume;
	snd_mixer_t *alsaMixerHandle;
#endif
	static eDVBVolumecontrol *instance;
	eDVBVolumecontrol();
#ifdef SWIG
	~eDVBVolumecontrol();
#endif
	int openMixer();
	void closeMixer(int fd);

	bool muted;
	int leftVol, rightVol;
	long min, max;
	int m_volsteps;

	int checkVolume(int vol);

public:
	static eDVBVolumecontrol* getInstance();

	void setVolumeSteps(int steps);
	void volumeUp(int left = eConfigManager::getConfigIntValue("config.usage.volumestep"), int right = eConfigManager::getConfigIntValue("config.usage.volumestep")); //j00zek
	void volumeDown(int left = eConfigManager::getConfigIntValue("config.usage.volumestep"), int right = eConfigManager::getConfigIntValue("config.usage.volumestep")); //j00zek

	void setVolume(int left, int right);

	void volumeMute();
	void volumeUnMute();
	void volumeToggleMute();

	int getVolume();
	bool isMuted();
};

#endif //__volume_h
