#pragma once
#include "Actor.h"
class Player final : public Actor
{
public:
	enum class Attacks
	{
		none		 = 0,
 		light_Attack = 1, //tap  j
		knok_up		 = 2, //hold j
		heavy_fist   = 3, //tap  k
		boomerang	 = 4, //hold k
	};

	Player();

	Player(const Player&) = delete;
	Player(Player&&) = delete;
	Player& operator=(const Player&) = delete;
	Player& operator=(Player&&) = delete;

	void Initialize();
	
	void Draw() const override;
	void Update(float elapsedSec) override;

	int GetHealth();
	int GetEnergy();

	bool HitEnemy(const Rectf& shapeEnemy);

	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e, float elapsedSec);
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e);

	OAMEntry sendOAM() override;


private:
	//Membervariabels
	
		//Doge roll
	bool m_IsInvincible;
	const float m_MaxInvincibleTime;
	float m_InvincibleTime;

		//Energy 
	float m_Energy;
	const int m_MaxEnergy;
	const float m_EnergyRegen;

		// Attacks
	const float m_MaxHoldTime;
	const float m_MinChargTime;
	float m_ChargedTime;

	Attacks m_Attack;

	static const int m_NrAttackHitBoxes{ 3 };
	int m_Attackdamage[m_NrAttackHitBoxes];
	Rectf m_AttacksHitBoxArr[m_NrAttackHitBoxes];



		//Sprites & animations
	const float m_MaxAnimationsTime;
	float m_AnimationTime;
	bool m_IsIdle;

	//functions
	void HandleMovment(float elapsedSec);
	void HandleDogeRoll(const Uint8* pStates, float elapsedSec);
	
};

