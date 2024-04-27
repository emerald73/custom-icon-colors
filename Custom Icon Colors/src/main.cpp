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

		bool enablePrimaryColor = Mod::get()->getSettingValue<bool>("enableColor1");
		bool enableSecondaryColor = Mod::get()->getSettingValue<bool>("enableColor2");
		bool enableGlow = Mod::get()->getSettingValue<bool>("enableGlow");
		bool enableSameDualColor = Mod::get()->getSettingValue<bool>("sameDualColor");
		cocos2d::ccColor3B primaryColor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("primaryColor");
		cocos2d::ccColor3B secondaryColor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("secondaryColor");
		cocos2d::ccColor3B glowColor = Mod::get()->getSettingValue<cocos2d::ccColor3B>("glowColor");

		if (enableSameDualColor) {
			if (enablePrimaryColor) {
				m_player1->setColor(primaryColor);
				m_player2->setColor(primaryColor);
			}

			if (enableSecondaryColor) {
				m_player1->setSecondColor(secondaryColor);
				m_player2->setSecondColor(secondaryColor);
			}
		} else if (!enableSameDualColor) {
			if (enablePrimaryColor) {
				m_player1->setColor(primaryColor);
				m_player2->setSecondColor(primaryColor);
			}

			if (enableSecondaryColor) {
				m_player1->setSecondColor(secondaryColor);
				m_player2->setColor(secondaryColor);
			}
		}

		if (enableGlow) {
			m_player1->m_glowColor = glowColor;
			m_player2->m_glowColor = glowColor;
			m_player1->updateGlowColor();
			m_player2->updateGlowColor();
		}
	}
};
