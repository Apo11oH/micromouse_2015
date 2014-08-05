#include "navsystem.h"

NavSystem::NavSystem(void):isRacing(false),enc_count(0),
            cur_v_r(0),cur_v_l(0),cur_itg(0),cur_time(0),
            old_err(0),old_prop(0),old_time(0)
{
}

void NavSystem::stopAll(void)
{
}

void NavSystem::moveForward(void)
{
}

void NavSystem::turnRight(void)
{
}

void NavSystem::turnLeft(void)
{
}

void NavSystem::turn180(void)
{
}

void NavSystem::runPid(void)
{
}

void NavSystem::calibratePid(void)
{
}

