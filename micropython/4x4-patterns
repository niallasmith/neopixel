import machine, neopixel, array
from random import randint
from time import ticks_ms, sleep_ms
from math import floor, sin, pi
pixels = neopixel.NeoPixel(machine.Pin(0),16)
capacitive_button = machine.Pin(1,machine.Pin.IN)
prev_button_state = 0
cap_button_state = 0
brightness = 64

def clear():
    for i in range(0,16):
        pixels[i] = (0,0,0)
    pixels.write()
        
def fill(r,g,b,start=0,stop=16):
    for i in range(start,stop):
        pixels[i] = (r,g,b)
    pixels.write()
        
def hold_input():
    cap_button_state = capacitive_button.value()
    while cap_button_state == 1:
        sleep_ms(10)
        cap_button_state = capacitive_button.value()
        

def ripple(direction = 1):
    hold_input()
    
    if direction != 1: direction = -1
    
    row_map = array.array('I',[6, 5, 4, 3, 5, 4, 3, 2, 4, 3, 2, 1, 3, 2, 1, 0])
    clear()
    
    cap_button_state = capacitive_button.value()
    
    while cap_button_state != 1:
        for i in range(0,16):
            r = floor((brightness/2) * (sin(0.52 * (row_map[i]) + direction * 0.001 * ticks_ms()) + 1))
            g = floor((brightness/2) * (sin(0.52 * (row_map[i]) + direction * 0.001 * ticks_ms() + 2.09) + 1))
            b = floor((brightness/2) * (sin(0.52 * (row_map[i]) + direction * 0.001 * ticks_ms() + 4.19) + 1))
            
            pixels[i] = (r,g,b)
            
        pixels.write()
        sleep_ms(10)
        cap_button_state = capacitive_button.value()
    
def spinning(direction = 1):
    hold_input()
    
    if direction != 1: direction = -1
    
    clock_angle_map = array.array('I',[135, 158, 203, 225, 113, 135, 225, 248, 68, 45, 315, 293, 45, 23, 338, 315])
    clear()
    
    cap_button_state = capacitive_button.value()
    
    while cap_button_state != 1:
        for i in range(0,16):
            r = floor((brightness/2) * (sin(direction * 0.001 * ticks_ms() + (clock_angle_map[i]) / 57.3) + 1))
            g = floor((brightness/2) * (sin(direction * 0.001 * ticks_ms() + (clock_angle_map[i]) / 57.3 + 2.09) + 1))
            b = floor((brightness/2) * (sin(direction * 0.001 * ticks_ms() + (clock_angle_map[i]) / 57.3 + 4.19) + 1))
            
            pixels[i] = (r,g,b)
            
        pixels.write()
        sleep_ms(10)
        cap_button_state = capacitive_button.value()
        
def chase(direction = 1):
    hold_input()
    
    if direction != 1: direction = -1
    
    wrap_map = array.array('I',[12, 13, 14, 15, 11, 10, 9, 8, 4, 5, 6, 7, 3, 2, 1, 0])
    clear()
    
    cap_button_state = capacitive_button.value()
    
    i = 0
    
    while cap_button_state != 1:
        clear()
        rand_offset = randint(0,64)
        r = floor((brightness/2) * (sin(0.1 * rand_offset) + 1))
        g = floor((brightness/2) * (sin(0.1 * rand_offset + 2.09) + 1))
        b = floor((brightness/2) * (sin(0.1 * rand_offset + 4.19) + 1))
        
        pixels[wrap_map[i]] = (r,g,b)
        
        pixels[wrap_map[i-1]] = (floor(0.75*r),floor(0.75*g),floor(0.75*b))
        
        pixels[wrap_map[i-2]] = (floor(0.5*r),floor(0.5*g),floor(0.5*b))
    
        pixels.write()
        i = (i + 1 * direction) % 16
        sleep_ms(350)
        cap_button_state = capacitive_button.value()
    
def RGBrandom():
    hold_input()
    
    clear()
    
    cap_button_state = capacitive_button.value()
    
    while cap_button_state != 1:
        rand_offset = randint(0,64)
        r = floor((brightness/2) * (sin(0.1 * rand_offset) + 1))
        g = floor((brightness/2) * (sin(0.1 * rand_offset + 2.09) + 1))
        b = floor((brightness/2) * (sin(0.1 * rand_offset + 4.19) + 1))
        
        fill(r,g,b)
        
        sleep_ms(500)
        
        cap_button_state = capacitive_button.value()
        
    
def snake():
    hold_input()
    
    clear()
    snake_map = array.array('I',[12, 13, 14, 15, 11, 10, 9, 8, 4, 5, 6, 7, 3, 2, 1, 0])
    
    cap_button_state = capacitive_button.value()
    
    while cap_button_state != 1:
        rand_offset = randint(0,64)
        r = floor((brightness/2) * (sin(0.1 * rand_offset) + 1))
        g = floor((brightness/2) * (sin(0.1 * rand_offset + 2.09) + 1))
        b = floor((brightness/2) * (sin(0.1 * rand_offset + 4.19) + 1))
        
        for i in range(0,16):
            pixels[snake_map[i]] = (r,g,b)
            pixels.write()
            if capacitive_button.value() == 1: break
            sleep_ms(250)
        
        for i in range(0,16):
            pixels[snake_map[15-i]] = (0,0,0)
            pixels.write()
            if capacitive_button.value() == 1: break
            sleep_ms(250)
        
        cap_button_state = capacitive_button.value()
    
def zigzag(direction = 1):
    hold_input()
    
    if direction != 1: direction = -1
    
    clear()
    zigzag_map = array.array('I',[4, 3, 4, 3, 3, 2, 3, 2, 2, 1, 2, 1, 1, 0, 1, 0])
    
    cap_button_state = capacitive_button.value()
    
    while cap_button_state != 1:
        for i in range(0,16):
            r = floor((brightness/2) * (sin(1.6 * zigzag_map[i] + 0.001 * ticks_ms() ) + 1))
            g = floor((brightness/2) * (sin(1.6 * zigzag_map[i] + 0.001 * ticks_ms() + 2.09) + 1))
            b = floor((brightness/2) * (sin(1.6 * zigzag_map[i] + 0.001 * ticks_ms() + 4.19) + 1))
        
            pixels[i] = (r,g,b)
            
        pixels.write()
        sleep_ms(10)
        
        cap_button_state = capacitive_button.value()
    
def hue_fade():
    hold_input()
    
    clear()
    
    cap_button_state = capacitive_button.value()
    
    while cap_button_state != 1:
        r = floor((brightness/2) * (sin(0.001 * ticks_ms() ) + 1))
        g = floor((brightness/2) * (sin(0.001 * ticks_ms() + 2.09) + 1))
        b = floor((brightness/2) * (sin(0.001 * ticks_ms() + 4.19) + 1))
        fill(r,g,b)
        sleep_ms(10)
        
        cap_button_state = capacitive_button.value()
        
def spiral(direction = 1):
    hold_input()
    
    if direction != 1: direction = -1
    
    spiral_map = array.array('I',[10, 9, 5, 6, 7, 11, 15, 14, 13, 12, 8, 4, 0, 1, 2, 3])
    clear()
    
    cap_button_state = capacitive_button.value()
    
    while cap_button_state != 1:
        for i in range(0,16):
            r = floor((brightness/2) * (sin(direction * 0.001 * ticks_ms() + 0.42 * spiral_map[i]) + 1))
            g = floor((brightness/2) * (sin(direction * 0.001 * ticks_ms() + 0.42 * spiral_map[i] + 2.09) + 1))
            b = floor((brightness/2) * (sin(direction * 0.001 * ticks_ms() + 0.42 * spiral_map[i] + 4.19) + 1))
            
            pixels[i] = (r,g,b)
            
        pixels.write()
        sleep_ms(10)
        cap_button_state = capacitive_button.value()
        
def layers():
    hold_input()
    
    clear()
    
    rand_offset = randint(0,64)
    r = floor((brightness/2) * (sin(0.1 * rand_offset) + 1))
    g = floor((brightness/2) * (sin(0.1 * rand_offset + 2.09) + 1))
    b = floor((brightness/2) * (sin(0.1 * rand_offset + 4.19) + 1))
    
    cap_button_state = capacitive_button.value()
    
    while cap_button_state != 1:
        for i in range(0,4):
            fill(r,g,b,4*i,4*(i+1))
            if capacitive_button.value() == 1: break
            sleep_ms(500)
            
        for i in range(0,4):
            fill(0,0,0,4*(i),4*(i+1))
            if capacitive_button.value() == 1: break
            sleep_ms(500)
            
        cap_button_state = capacitive_button.value()
        
def wave(direction = 1):
    hold_input()
    
    if direction != 1: direction = -1
    
    wave_map = array.array('I',[10, 9, 5, 6, 7, 11, 15, 14, 13, 12, 8, 4, 0, 1, 2, 3])
    clear()
    
    cap_button_state = capacitive_button.value()
    
    while cap_button_state != 1:
        for i in range(0,16):
            r = floor((brightness/2) * (sin(direction * 0.001 * ticks_ms() + 0.42 * wave_map[i]) + 1))
            g = floor((brightness/2) * (sin(direction * 0.001 * ticks_ms() + 0.42 * wave_map[i] + 2.09) + 1))
            b = floor((brightness/2) * (sin(direction * 0.001 * ticks_ms() + 0.42 * wave_map[i] + 4.19) + 1))
            
            pixels[wave_map[i]] = (r,g,b)
            
        pixels.write()
        sleep_ms(10)
        cap_button_state = capacitive_button.value()
        
def flow(direction = 1):
    hold_input()
    
    if direction != 1: direction = -1
    
    flow_map = array.array('I',[0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3])
    clear()
    
    cap_button_state = capacitive_button.value()
    
    while cap_button_state != 1:
        for i in range(0,16):
            r = floor((brightness/2) * (sin(direction * 0.002 * ticks_ms() + 0.79 * flow_map[i]) + 1))
            g = floor((brightness/2) * (sin(direction * 0.002 * ticks_ms() + 0.79 * flow_map[i] + 2.09) + 1))
            b = floor((brightness/2) * (sin(direction * 0.002 * ticks_ms() + 0.79 * flow_map[i] + 4.19) + 1))
            
            pixels[i] = (r,g,b)
            
        pixels.write()
        sleep_ms(10)
        cap_button_state = capacitive_button.value()
    
while True:
    spinning(randint(0,1))
    ripple(randint(0,1))
    chase(randint(0,1))
    RGBrandom()
    snake()
    zigzag(randint(0,1))
    hue_fade()
    spiral(randint(0,1))
    layers()
    wave(randint(0,1))
    flow(randint(0,1))
