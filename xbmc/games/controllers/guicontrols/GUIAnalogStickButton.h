/*
 *      Copyright (C) 2016-2017 Team Kodi
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "GUIFeatureButton.h"

namespace KODI
{
namespace GAME
{
  class CGUIAnalogStickButton : public CGUIFeatureButton
  {
  public:
    CGUIAnalogStickButton(const CGUIButtonControl& buttonTemplate,
                          IConfigurationWizard* wizard,
                          const CControllerFeature& feature,
                          unsigned int index);

    virtual ~CGUIAnalogStickButton(void) { }

    // implementation of IFeatureButton
    virtual bool PromptForInput(CEvent& waitEvent) override;
    virtual bool IsFinished(void) const override;
    virtual JOYSTICK::ANALOG_STICK_DIRECTION GetDirection(void) const override;
    virtual void Reset(void) override;

  private:
    enum class STATE
    {
      ANALOG_STICK_UP,
      ANALOG_STICK_RIGHT,
      ANALOG_STICK_DOWN,
      ANALOG_STICK_LEFT,
      FINISHED,
    };

    STATE m_state;
  };
}
}
