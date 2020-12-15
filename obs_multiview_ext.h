#ifndef OBS_MULTIVIEW_EXT_H
#define OBS_MULTIVIEW_EXT_H

#include <obs-module.h>

/* Defines common functions (required) */
OBS_DECLARE_MODULE()

class Obs_multiview_ext
{
public:
    Obs_multiview_ext();
};

#define blog(level, msg, ...) blog(level, "[obs-multiview-ext] " msg, ##__VA_ARGS__)

#endif    // OBS_MULTIVIEW_EXT_H
