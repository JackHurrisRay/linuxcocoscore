/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   jackThread.cpp
 * Author: Jack.L
 * 
 * Created on 2017年7月11日, 下午8:37
 */

#include "jackThread.h"

////////////////
void* func_thread(void* arg)
{
    JackThread* _thread = (JackThread*)arg;
    _thread->process();
    _thread->end();
}

JackThread::JackThread(JACK_FUNC_THREAD _fProcess, JACK_FUNC_THREAD _fEnd)
{
    m_funcProcess = _fProcess;
    m_funcEnd     = _fEnd;    
}

JackThread::~JackThread()
{
    
}

void JackThread::begin()
{
    m_thread_status = 0;
    
    pthread_create(
            &m_threadID,
            NULL,
            &func_thread,
            this
        );
}

void JackThread::process()
{
    if( m_funcProcess )
    {
        m_funcProcess();        
    }       
    
    m_thread_status = 1;    

}

void JackThread::end()
{
    if( m_funcEnd )
    {
        m_funcEnd();        
    }
    
    m_thread_status = 2;
}

////////////////
void* func_cys_thread(void* arg)
{
    JackThreadCys* _thread = (JackThreadCys*)arg;
    _thread->process();
    _thread->end();
}

JackThreadCys::JackThreadCys(JACK_FUNC_THREAD _fProcess, JACK_FUNC_THREAD _fEnd):
JackThread::JackThread( _fProcess, _fEnd )
{
    
}

JackThreadCys::~JackThreadCys()
{
    
}

void JackThreadCys::begin()
{
    m_thread_status = 0;
            
    pthread_create(
            &m_threadID,
            NULL,
            &func_cys_thread,
            this
        );
}

void JackThreadCys::process()
{
    while( m_thread_status == 0 )
    {
        if( m_funcProcess )
        {
            m_funcProcess();        
        }        
    }    
}

void JackThreadCys::stop()
{
    m_thread_status = 1;
}