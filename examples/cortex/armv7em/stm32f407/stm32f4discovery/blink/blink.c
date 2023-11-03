#include "tp.h"
#include "tpl_os.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}


//led4 odr12
//led3 odr13
//led5 odr14
/********************TASKS*************************/
TASK(blink)
{
  ledToggle(LED4);
  ActivateTask(blinkOne);
  ActivateTask(blinkTow);

 
  for (long int i = 0; i < 500000; ++i);
  ledToggle(LED4);
  for (long int i = 0; i < 500000; ++i);

  TerminateTask();
}


TASK(blinkOne)
{
  ledToggle(LED3);
  for (int i = 0; i < 500000; ++i);
  ledToggle(LED3);
  for (int i = 0; i < 500000; ++i);
  TerminateTask();
}

TASK(blinkTow)
{
  ledToggle(LED5);
  for (int i = 0; i < 500000; ++i);
  ledToggle(LED5);
  for (int i = 0; i < 500000; ++i);
    
  TerminateTask();
}

/***************************************************/


#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

FUNC(void, OS_CODE) PreTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
    ledOn(ORANGE);
  }
}

FUNC(void, OS_CODE) PostTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
    ledOff(ORANGE);
  }
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

