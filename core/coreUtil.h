/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   coreUtil.h
 * Author: Jack.L
 *
 * Created on 2017年7月13日, 下午1:58
 */

#ifndef COREUTIL_H
#define COREUTIL_H

#include "cocos2d.h"

class JackLabelAtlas:public cocos2d::LabelAtlas
{
public:

    ////////
    void setIgnoreContentScaleFactorEx(bool bIgnoreContentScaleFactor);
        
    CREATE_FUNC(JackLabelAtlas);
        
};





#endif /* COREUTIL_H */

