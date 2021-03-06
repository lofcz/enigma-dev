/********************************************************************************\
**                                                                              **
**  Copyright (C) 2013 forthevin                                                **
**                                                                              **
**  This file is a part of the ENIGMA Development Environment.                  **
**                                                                              **
**                                                                              **
**  ENIGMA is free software: you can redistribute it and/or modify it under the **
**  terms of the GNU General Public License as published by the Free Software   **
**  Foundation, version 3 of the license or any later version.                  **
**                                                                              **
**  This application and its source code is distributed AS-IS, WITHOUT ANY      **
**  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS   **
**  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more       **
**  details.                                                                    **
**                                                                              **
**  You should have recieved a copy of the GNU General Public License along     **
**  with this code. If not, see <http://www.gnu.org/licenses/>                  **
**                                                                              **
**  ENIGMA is an environment designed to create games and other programs with a **
**  high-level, fully compilable language. Developers of ENIGMA or anything     **
**  associated with ENIGMA are in no way responsible for its users or           **
**  applications created by its users, or damages caused by the environment     **
**  or programs made in the environment.                                        **
**                                                                              **
\********************************************************************************/

#ifndef ENIGMA_PS_EFFECTSCONSTANTS
#define ENIGMA_PS_EFFECTSCONSTANTS

namespace enigma_user {
  enum
  {
    ef_explosion = 0,
    ef_ring,
    ef_ellipse,
    ef_firework,
    ef_smoke,
    ef_smokeup,
    ef_star,
    ef_spark,
    ef_flare,
    ef_cloud,
    ef_rain,
    ef_snow
  };

  enum
  {
    ef_size_small = 0,
    ef_size_medium,
    ef_size_large,
  };
}

#endif // ENIGMA_PS_EFFECTSCONSTANTS

