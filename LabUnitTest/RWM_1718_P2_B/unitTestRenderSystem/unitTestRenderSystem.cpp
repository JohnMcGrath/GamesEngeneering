#include "gtest\gtest.h"
#include "RenderSystem.h"
#include "RenderComponent.h"

TEST(testRender, simpleTest) 
{
	RenderSystem rnd;
	EXPECT_EQ(false, rnd.getfoundComponent());
}

TEST(testRender, entityTest)
{
	RenderSystem* rnd = new RenderSystem();
	Entity* player = new Entity();
	RenderComponent* rnCom = new RenderComponent();
	player->addComponent(rnCom);
	rnd->addEntity(player);
	rnd->update();
	
	EXPECT_EQ(true, rnd->getfoundComponent());
}