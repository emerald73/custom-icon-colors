#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/cocos/include/ccTypes.h>
#include <Geode/loader/Mod.hpp>

using namespace geode::prelude;

class $modify(PlayerObject) {
  void flashPlayer(float p0, float p1, cocos2d::ccColor3B mainColor, cocos2d::ccColor3B secondColor) {
  }
	void updateGlowColor() {
		PlayerObject::updateGlowColor();
	}
};

class $modify(PlayLayer) {
	void postUpdate(float p0) {
		PlayLayer::postUpdate(p0);

		bool enablePrimaryColorP1 = Mod::get()->getSettingValue<bool>("enablePrimaryColorP1");
		bool enableSecondaryColorP1 = Mod::get()->getSettingValue<bool>("enableSecondaryColorP1");
    bool enablePrimaryColorP2 = Mod::get()->getSettingValue<bool>("enablePrimaryColorP2");
		bool enableSecondaryColorP2 = Mod::get()->getSettingValue<bool>("enableSecondaryColorP2");
		bool enableGlowP1 = Mod::get()->getSettingValue<bool>("enableGlowP2");
		bool enableGlowP2 = Mod::get()->getSettingValue<bool>("enableGlowP1");
		bool enableSameDualColor = Mod::get()->getSettingValue<bool>("sameDualColor");
		cocos2d::ccColor3B primaryColorP1 = Mod::get()->getSettingValue<cocos2d::ccColor3B>("primaryColorP1");
		cocos2d::ccColor3B secondaryColorP1 = Mod::get()->getSettingValue<cocos2d::ccColor3B>("secondaryColorP1");
    cocos2d::ccColor3B primaryColorP2 = Mod::get()->getSettingValue<cocos2d::ccColor3B>("primaryColorP2");
		cocos2d::ccColor3B secondaryColorP2 = Mod::get()->getSettingValue<cocos2d::ccColor3B>("secondaryColorP2");
		cocos2d::ccColor3B glowColorP1 = Mod::get()->getSettingValue<cocos2d::ccColor3B>("glowColorP1");
    cocos2d::ccColor3B glowColorP2 = Mod::get()->getSettingValue<cocos2d::ccColor3B>("glowColorP2");

		if (enableSameDualColor) {
			if (enablePrimaryColorP1) {
				m_player1->setColor(primaryColorP1);
			}

      if(enablePrimaryColorP2) {
        m_player2->setColor(primaryColorP2);
      }

			if (enableSecondaryColorP1) {
				m_player1->setSecondColor(secondaryColorP1);
			}

      if (enableSecondaryColorP2) {
        m_player2->setSecondColor(secondaryColorP2);
      }
		} else if (!enableSameDualColor) {
			if (enablePrimaryColorP1) {
				m_player1->setColor(primaryColorP1);
			}

      if (enablePrimaryColorP2) {
        m_player2->setSecondColor(primaryColorP2);
      }

			if (enableSecondaryColorP1) {
				m_player1->setSecondColor(secondaryColorP1);
			}

      if (enableSecondaryColorP2) {
        m_player2->setColor(secondaryColorP2);
      }
		}

		if (enableGlowP1) {
			m_player1->m_glowColor = glowColorP1;
			m_player1->updateGlowColor();
		}

    if (enableGlowP2) {
      m_player2->m_glowColor = glowColorP2;
			m_player2->updateGlowColor();
    }
	}
};
