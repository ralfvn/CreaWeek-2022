#pragma once
#include "Enemy.h"

class SmallEnemy : public Enemy
{
public:
	SmallEnemy( Point2f pos );
	virtual ~SmallEnemy();

	SmallEnemy(const SmallEnemy& other) = delete;
	SmallEnemy& operator=(const SmallEnemy& other) = delete;
	SmallEnemy(SmallEnemy&& other) = delete;
	SmallEnemy& operator=(SmallEnemy&& other) = delete;

	void IsInRange( Actor* player );

	virtual void Update(float elapsedSec) override;
	bool isReflecting() const;

protected:
	void movement();
	void changeActionState();
	void changeAttack();

	virtual void doAttack();

	enum class actionState
	{
		moving,
		idle,
		dying
	};
	enum class attacks
	{
		none,
		melee,
		reflect
	};

	actionState m_Action;
	attacks m_Attack;

	bool isActorOverlapping( Actor* player );

	bool m_IslookingLeft;
	Rectf m_RangeRect;
	Actor* m_pPlayer;

private:
	

};

