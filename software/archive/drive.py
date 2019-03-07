#Import Adafruit libraries
import Adafruit_BBIO.GPIO as GPIO
import Adafruit_BBIO.PWM as PWM 

#Front Right Pins
FR_PWM = "P9_14"
FR_DIR_A = "P9_12"
FR_DIR_B = "P9_11"

#Front Left Pins
FL_PWM = "P9_16"
FL_DIR_A = "P9_13"
FL_DIR_B = "P9_15"

#Back Right Pins
BR_PWM = "P9_21"
BR_DIR_A = "P9_23"
BR_DIR_B = "P9_24"

#Back Left Pins
BL_PWM = "P9_22"
BL_DIR_A = "P9_18"
BL_DIR_B = "P9_17"

POWER = 50

def setup():
    GPIO.setup(FR_DIR_A, GPIO.OUT )
    GPIO.setup(FR_DIR_B, GPIO.OUT )
    GPIO.setup(FL_DIR_A, GPIO.OUT )
    GPIO.setup(FL_DIR_B, GPIO.OUT )
    GPIO.setup(BR_DIR_A, GPIO.OUT )
    GPIO.setup(BR_DIR_B, GPIO.OUT )
    GPIO.setup(BL_DIR_A, GPIO.OUT )
    GPIO.setup(BL_DIR_B, GPIO.OUT )
    return

def frTest():
    PWM.start(FR_PWM, POWER)
    GPIO.output(FR_DIR_A, GPIO.HIGH)
    GPIO.output(FR_DIR_B, GPIO.LOW)
    return

def flTest():
    PWM.start(FL_PWM, POWER)
    GPIO.output(FL_DIR_A, GPIO.HIGH)
    GPIO.output(FL_DIR_B, GPIO.LOW)
    return

def brTest():
    PWM.start(BR_PWM, POWER)
    GPIO.output(BR_DIR_A, GPIO.HIGH)
    GPIO.output(BR_DIR_B, GPIO.LOW)
    return

def blTest():
    PWM.start(BL_PWM, POWER)
    GPIO.output(BL_DIR_A, GPIO.HIGH)
    GPIO.output(BL_DIR_B, GPIO.LOW)
    return

def backward():
    PWM.start(FR_PWM, POWER)
    GPIO.output(FR_DIR_A, GPIO.LOW)
    GPIO.output(FR_DIR_B, GPIO.HIGH)

    PWM.start(FL_PWM, POWER)
    GPIO.output(FL_DIR_A, GPIO.LOW)
    GPIO.output(FL_DIR_B, GPIO.HIGH)

    PWM.start(BR_PWM, POWER)
    GPIO.output(BR_DIR_A, GPIO.LOW)
    GPIO.output(BR_DIR_B, GPIO.HIGH)

    PWM.start(BL_PWM, POWER)
    GPIO.output(BL_DIR_A, GPIO.LOW)
    GPIO.output(BL_DIR_B, GPIO.HIGH)

    return

def forward():
    PWM.start(FR_PWM, POWER)
    GPIO.output(FR_DIR_A, GPIO.HIGH)
    GPIO.output(FR_DIR_B, GPIO.LOW)

    PWM.start(FL_PWM, POWER)
    GPIO.output(FL_DIR_A, GPIO.HIGH)
    GPIO.output(FL_DIR_B, GPIO.LOW)

    PWM.start(BR_PWM, POWER)
    GPIO.output(BR_DIR_A, GPIO.HIGH)
    GPIO.output(BR_DIR_B, GPIO.LOW)

    PWM.start(BL_PWM, POWER)
    GPIO.output(BL_DIR_A, GPIO.HIGH)
    GPIO.output(BL_DIR_B, GPIO.LOW)

    return

def left():
    PWM.start(FR_PWM, POWER)
    GPIO.output(FR_DIR_A, GPIO.HIGH)
    GPIO.output(FR_DIR_B, GPIO.LOW)

    PWM.start(FL_PWM, POWER)
    GPIO.output(FL_DIR_A, GPIO.LOW)
    GPIO.output(FL_DIR_B, GPIO.HIGH)

    PWM.start(BR_PWM, POWER)
    GPIO.output(BR_DIR_A, GPIO.LOW)
    GPIO.output(BR_DIR_B, GPIO.HIGH)

    PWM.start(BL_PWM, POWER) 
    GPIO.output(BL_DIR_A, GPIO.HIGH)
    GPIO.output(BL_DIR_B, GPIO.LOW)

    return

def right():
    PWM.start(FR_PWM, POWER)
    GPIO.output(FR_DIR_A, GPIO.LOW)
    GPIO.output(FR_DIR_B, GPIO.HIGH)

    PWM.start(FL_PWM, POWER)
    GPIO.output(FL_DIR_A, GPIO.HIGH)
    GPIO.output(FL_DIR_B, GPIO.LOW)

    PWM.start(BR_PWM, POWER)
    GPIO.output(BR_DIR_A, GPIO.HIGH)
    GPIO.output(BR_DIR_B, GPIO.LOW)

    PWM.start(BL_PWM, POWER)
    GPIO.output(BL_DIR_A, GPIO.LOW)
    GPIO.output(BL_DIR_B, GPIO.HIGH)

    return

def stop():
    PWM.start(FR_PWM, 0)
    GPIO.output(FR_DIR_A, GPIO.LOW)
    GPIO.output(FR_DIR_B, GPIO.LOW)

    PWM.start(FL_PWM, 0)
    GPIO.output(FL_DIR_A, GPIO.LOW)
    GPIO.output(FL_DIR_B, GPIO.LOW)

    PWM.start(BR_PWM, 0)
    GPIO.output(BR_DIR_A, GPIO.LOW)
    GPIO.output(BR_DIR_B, GPIO.LOW)

    PWM.start(BL_PWM, 0)
    GPIO.output(BL_DIR_A, GPIO.LOW)
    GPIO.output(BL_DIR_B, GPIO.LOW)

    return

