# Simple demo of of the PCA9685 PWM servo/LED controller library.
# This will move channel 0 from min to max position repeatedly.
# Author: Tony DiCola
# License: Public Domain
from __future__ import division
import time
import curses
# Import the PCA9685 module.
import Adafruit_PCA9685


screen = curses.initscr()
# turn off input echoing
curses.noecho()
# respond to keys immediately (don't wait for enter)
curses.cbreak()
# map arrow keys to special values
screen.keypad(True)

# Uncomment to enable debug output.
#import logging
#logging.basicConfig(level=logging.DEBUG)

# Initialise the PCA9685 using the default address (0x40).
pwm = Adafruit_PCA9685.PCA9685()

# Alternatively specify a different address and/or bus:
#pwm = Adafruit_PCA9685.PCA9685(address=0x41, busnum=2)
#x pulse length out of 4096


# Configure min and max servo pulse lengths
servo_min = 1024  # Min pulse length out of 4096
servo_max = 650  # Max pulse length out of 4096

# Helper function to make setting a servo pulse width simpler.
def set_servo_pulse(channel, pulse):
    pulse_length = 1000000    # 1,000,000 us per second
    pulse_length //= 60       # 60 Hz
    print('{0}us per period'.format(pulse_length))
    pulse_length //= 4096     # 12 bits of resolution
    print('{0}us per bit'.format(pulse_length))
    pulse *= 1000
    pulse //= pulse_length
    pwm.set_pwm(channel, 0, pulse)

# Set frequency to 60hz, good for servos.
pwm.set_pwm_freq(50)

print('Moving servo on channel 0, press Ctrl-C to quit...')
#while True:
     # Move servo on channel O between extremes.
print "cycle start"
#pwm.set_pwm(0, 4096, 0)
#time.sleep(3)
	
#pwm.set_pwm(0, 0, 4096)
#time.sleep(2)
#pwm.set_pwm(0, 0, servo_min)


#pwm.set_pwm(0, 0, 0)
#time.sleep(4)
#)
#time.sleep(1)
    #pwm.set_pwm(0, 0, servo_max)

    #time.sleep(1)

try:
    while True:
      char = screen.getch()
      if char == ord('q'):
      	 print "hi spencer" 
      else:

         if char == curses.KEY_UP:
		pwm.set_pwm(0, 0, 410) #this is the set to max value for the throttle, throttle max should be about 2 ms duty cycle and min should be about 1 ms duty cycle
		pwm.set_pwm(1, 0, 410) #this is the set to max value for the throttle, throttle max should be about 2 ms duty cycle and min should be about 1 ms duty cycle
		pwm.set_pwm(2, 0, 410) #this is the set to max value for the throttle, throttle max should be about 2 ms duty cycle and min should be about 1 ms duty cycle
		pwm.set_pwm(3, 0, 410) #this is the set to max value for the throttle, throttle max should be about 2 ms duty cycle and min should be about 1 ms duty cycle


#		pwm.set_pwm(3, 4096, 0)
		print char
	 elif char == 97: #a
		pwm.set_pwm(0, 0, 410)
	 elif char == 119: #w
		pwm.set_pwm(5, 4096, 0)
	 elif char == 115: #s
		pwm.set_pwm(5, 0,0) 	
	 elif char == 100: #d
		pwm.set_pwm(3, 0, 410)
	 elif char == curses.KEY_RIGHT:
		pwm.set_pwm(0, 0, 307) 
		pwm.set_pwm(1, 0, 307) 
		pwm.set_pwm(2, 0, 307) 
		pwm.set_pwm(3, 0, 307) 
		print char
	 elif char == curses.KEY_LEFT:
		pwm.set_pwm(0, 0, 350) 
		pwm.set_pwm(1, 0, 350) 
		pwm.set_pwm(2, 0, 350) 
		pwm.set_pwm(3, 0, 350) 
		
     	 elif char == curses.KEY_DOWN:
#        	pwm.set_pwm(3, 0, 4096)
		pwm.set_pwm(0, 0, 205)   #min range needs to be around 1 ms so 205 is used as the minimum value	 
		pwm.set_pwm(1, 0, 205)   #min range needs to be around 1 ms so 205 is used as the minimum value	 
		pwm.set_pwm(2, 0, 205)   #min range needs to be around 1 ms so 205 is used as the minimum value	 
		pwm.set_pwm(3, 0, 205)   #min range needs to be around 1 ms so 205 is used as the minimum value	 
		print char
	
# 	 elif char == ord('t'):
#4            	
#            numb = numbmin

#      pwm.setPWM(0, 0, numb)

#set_pwm(0, 0, 205) 
finally:
    # shut down cleanly
	curses.nocbreak(); screen.keypad(0); curses.echo()
	curses.endwin()
  # print(numb)

