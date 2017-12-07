#include "gtest\gtest.h"
#include "RenderSystem.h"
#include "RenderComponent.h"
#include "AIComponent.h"

TEST(testRender, simpleTest) 
{
	RenderSystem rnd;
	EXPECT_EQ(false, rnd.getfoundComponent());
}

TEST(testRender, entityCorrectTest)
{
	RenderSystem* rnd = new RenderSystem();
	Entity* player = new Entity();
	RenderComponent* rnCom = new RenderComponent();
	player->addComponent(rnCom);
	rnd->addEntity(player);
	rnd->update();
	
	EXPECT_EQ(true, rnd->getfoundComponent());
}

TEST(testRender, entityWrongComponentTest)
{
	RenderSystem* rnd = new RenderSystem();
	Entity* player = new Entity();
	AIComponent* aiCom = new AIComponent();
	player->addComponent(aiCom);
	rnd->addEntity(player);
	rnd->update();

	EXPECT_EQ(false, rnd->getfoundComponent());
}

TEST(testRender, entityNotPresentTest)
{
	RenderSystem* rnd = new RenderSystem();
	Entity* player = new Entity();
	rnd->update();

	EXPECT_EQ(false, rnd->getfoundComponent());
}

TEST(testRender, entityMultipleComponentsTest)
{
	RenderSystem* rnd = new RenderSystem();
	Entity* player = new Entity();
	AIComponent* aiCom = new AIComponent();
	RenderComponent* rnCom = new RenderComponent();

	player->addComponent(aiCom);
	player->addComponent(rnCom);
	rnd->addEntity(player);
	rnd->update();

	EXPECT_EQ(true, rnd->getfoundComponent());
}

TEST(testRender, entityNoComponentTest)
{
	RenderSystem* rnd = new RenderSystem();
	Entity* player = new Entity();
	rnd->addEntity(player);
	rnd->update();

	EXPECT_EQ(false, rnd->getfoundComponent());
}