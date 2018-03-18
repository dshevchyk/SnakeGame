//
//  MenuLayer.cpp
//  ExpJam
//
//  Created by dmytros on 18/03/2018.
//
//

#include "MenuLayer.h"
#include "IMenuDelegate.h"
USING_NS_CC;

void MenuLayer::onEnter()
{
    Layer::onEnter();
}
// scene hidden
void MenuLayer::onExit()
{
    Layer::onExit();
}

// on "init" you need to initialize your instance
bool MenuLayer::init()
{
    // super init first
    if ( !Layer::init() )
    {
        return false;
    }
    MenuItemFont::setFontSize(20);
    MenuItemFont*startMenuItem = MenuItemFont::create("Start game",
                                                          [this](Ref* pSender){
                                                              if(m_Delegate)
                                                              {
                                                                  m_Delegate->onStartClicked();
                                                              }
                                                          });

    MenuItemFont *multiplayerMenuItem = MenuItemFont::create("Multiplayer",
                                                      [this](Ref* pSender){
                                                          if(m_Delegate)
                                                          {
                                                              m_Delegate->onMultiplayerClicked();
                                                          }
                                                      });
    //is not supported yet
    multiplayerMenuItem->setEnabled(false);
    MenuItemFont *settingMenuItem = MenuItemFont::create("Settings",
                                                           [this](Ref* pSender){
                                                               if(m_Delegate)
                                                               {
                                                                   m_Delegate->onSettingsClicked();
                                                               }
                                                           });
    //is not supported yet
    settingMenuItem->setEnabled(false);
    MenuItemFont *helpMenuItem = MenuItemFont::create("Help",
                                                        [this](Ref* pSender){
                                                            if(m_Delegate)
                                                            {
                                                                m_Delegate->onHelpClicked();
                                                            }
                                                        });
    //is not supported yet
    helpMenuItem->setEnabled(false);
    MenuItemFont *exitMenuItem = MenuItemFont::create("Exit",
                                                      [this](Ref* pSender){
                                                          if(m_Delegate)
                                                          {
                                                              m_Delegate->onExitClicked();
                                                          }
                                                      });
    
    Menu*mu = Menu::create(startMenuItem, multiplayerMenuItem, settingMenuItem, helpMenuItem, exitMenuItem, NULL);
    mu->setPosition(Vec2(0, 0));
    mu->alignItemsVerticallyWithPadding(20);
    this->addChild(mu);
    
    return true;
}

void MenuLayer::setDelegate (IMenuDelegate* delegate)
{
    m_Delegate = delegate;
}
const IMenuDelegate* MenuLayer::getDelegate() const
{
    return m_Delegate;
}
