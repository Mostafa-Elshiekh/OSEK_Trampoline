/**
 * @file autosar_tp_s9/task1_instance.c
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */


/*Instance 1 of task t1*/

#include "Os.h"


/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
 
  SCHEDULING_CHECK_STEP(1);
  sendSoftwareIt(0, SOFT_IRQ0); /* Start inter-arrival time */ 
  
  SCHEDULING_CHECK_STEP(3);
  /* Wait isr1 Time Frame elapsed */
  sendSoftwareIt(0, SOFT_IRQ0);
  
  SCHEDULING_CHECK_STEP(5);
  /* Don't Wait isr1 Time Frame elapsed */
  sendSoftwareIt(0, SOFT_IRQ0); /* --> ProtectionHook */
  
  SCHEDULING_CHECK_STEP(7);
  /* Wait isr1 Time Frame elapsed */
  sendSoftwareIt(0, SOFT_IRQ0);
  
  SCHEDULING_CHECK_STEP(11);
  sendSoftwareIt(0, SOFT_IRQ1); /* if ISR2 Time Frame are started from the activation point, this should not result in a ProtectionHook */
  
  SCHEDULING_CHECK_STEP(13);

  
}

/*create the test suite with all the test cases*/
TestRef AutosarTPTest_seq9_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarTPTest,"AutosarTPTest_sequence9",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarTPTest;
}


/* End of file autosar_tp_s9/task1_instance.c */
