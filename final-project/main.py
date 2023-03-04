# Final Project
# CS 111, Reckinger
# Nefthali Arizmendi, November 29, 2022
# A game where you help clean up trash for a sea turtle family.

import turtle
import random
import time

global phase 
global loaded
global trash
global locked
global completeGame1
global completeGame2
global completeGame3
global counter
counter = 0
completeGame1 = False
completeGame2 = False
completeGame3 = False
locked = False
loaded = True
phase = -1

def space():
    global phase
    global loaded
    global baby
    global locked
    global sis
    global counter
    
# MOM INTRO
    if phase == -1 and loaded == False:
        text.clear()
        text.goto(0, 100)
        text.write("Thank you very much!", False, align='center', font=('Arial', 20))
        text.goto(0, 60)
        text.write("Press 'Space' to continue", False, align='center', font=('Arial', 14))
        phase = 0
        
    elif phase == 0 and loaded == False:
        phase = 1

# SELECT GAME 
    if phase == 1 and loaded == False:

# Hide Mom and Change Background
        hideMenu()
        loaded = True
        locked = False
        s.bgpic("water.gif")
        
        text.goto(0, 250)
        text.write("Choose a turtle to help!", False, align='center', font=('Arial', 20))
        
# Game Graphics
        game1.showturtle()
        game2.showturtle()
        game3.showturtle()
        if completeGame3 == True:
           check3.showturtle()
        if completeGame2 == True:
           check2.showturtle()
        if completeGame1 == True:
           check1.showturtle()
           if completeGame2 == True:
              if completeGame3 == True:
                 global victory
                 victory.showturtle()

# GAME 1 
    elif phase == 2 and loaded == False:
        hideMenu()
        loaded = True
        locked = True

# Mom and Baby Turtle Set-up
        mom.shape("momtiny.gif")
        mom.goto(325,250)
        mom.showturtle()    
        baby.shape("baby.gif")
        baby.goto(-335, -335)
        baby.showturtle()
        text.goto(0,325)
        text.write("Help the baby turtle reach the mommy turtle while avoiding the trash!", False, align='center', font=('Arial', 18))
        text.goto(0,275)
        text.write("Use the arrow keys to guide baby turtle!", False, align='center', font=('Arial', 16))
        
# Generate Trash Function
        generateTrash()
        locked = False       
   
# GAME 2                   
    elif phase == 3 and loaded == False:
        locked = True
        hideMenu()
        loaded = True
        counter = 0
        sis.showturtle()
        text.goto(0,325)
        text.write("Help the young sister turtle escape from the rubbish!", False, align='center', font=('Arial', 18))
        text.goto(0,275)
        text.write("Click on the trash to remove it!", False, align='center', font=('Arial', 16))
        generateTrash()
        locked = False

# GAME 3   
    if phase == 4 and loaded == False:
        hideMenu()
        t.clearstamps()
        t.hideturtle()
        loaded = True
        locked = True
        counter = 0
        s.bgpic("homedull.gif")
        text.goto(0,365)
        text.write("Our home is covered in filth! Help me clean up the trash please!", False, align='center', font=('Arial', 18))
        text.goto(0,343)
        text.write("Use the arrow keys to guide mommy turtle remove the trash!", False, align='center', font=('Arial', 16))
        generateTrash()
        locked = False
        baby = turtle.Turtle()
        baby.hideturtle()
        baby.shape("momtiny.gif")
        baby.penup()
        baby.goto(0, 0)
        baby.showturtle()

# Win Screen
def congratulations(x, y):
    hideMenu()
    t.clearstamps()
    t.hideturtle()
    global locked
    locked = True
    phase = "Win"
    s.bgpic("home.gif")
    mom.shape("game3.gif")
    mom.goto(-20, -125)
    mom.showturtle()
    victory.hideturtle()
    baby.shape("game1.gif")
    baby.goto(-105, -180)
    baby.showturtle()
    sis.shape("game2.gif")
    sis.goto(130, -170)
    sis.showturtle()
    text.goto(0,345)
    
    file = open('congratulations.txt')
    text_list = file.readlines()
    file.close()

    for i in range(len(text_list)):
        text_list[i] = text_list[i].strip()
        text_list[i] = text_list[i].capitalize()
    text_list[1].split()
    
    text.write(str(text_list[0]) + " " + str(text_list[1]), False, align='center', font=('Arial', 20))
    
# Clearing Previous Menu/Game Artifacts
def hideMenu():
    global loaded
    global trash
    global baby
    text.clear()
    mom.hideturtle()
    victory.hideturtle()
    game1.hideturtle()
    game2.hideturtle()
    game3.hideturtle() 
     
    if completeGame1 == True:
        check1.hideturtle()
        baby.hideturtle()
        for i in trash:
            i.hideturtle()
    if completeGame2 == True:
        sis.hideturtle()
        check2.hideturtle()
    loaded = False
    if completeGame3 == True:
        baby.hideturtle()
        check3.hideturtle()
    loaded = False
    
# Input Functions
def up():
    if phase == 2 and locked == False:
      baby.setheading(90)
      if (baby.ycor() + 20) < 300:
        baby.forward(20)
      detect()
    if phase == 4 and locked == False:
      baby.setheading(90)
      if (baby.ycor() + 20) < 350:
        baby.forward(20)
      detect()
      
def down():
    if phase == 2 and locked == False:
      baby.setheading(270)
      if (baby.ycor() - 20) > -350:
        baby.forward(20)
      detect()
    if phase == 4 and locked == False:
      baby.setheading(270)
      if (baby.ycor() - 20) > -350:
        baby.forward(20)
      detect()
      
def left():
    if phase == 2 and locked == False:
      baby.setheading(180)
      if (baby.xcor() - 20) > -350:
        baby.forward(20)
      detect()
    if phase == 4 and locked == False:
      baby.setheading(180)
      if (baby.xcor() - 20) > -350:
        baby.forward(20)
      detect()
      
def right() :
    if phase == 2 and locked == False:
      baby.setheading(0)
      if (baby.xcor() + 20) < 350:
        baby.forward(20)
      detect()
    if phase == 4 and locked == False:
      baby.setheading(0)
      if (baby.xcor() + 20) < 350:
        baby.forward(20)
      detect()      

# On Click, Game Selection
def click(x, y):
    global phase
    global locked
    global loaded
    global trash
    global counter
    global completeGame2
     
# Clearing Trash on Sister Turtle
    if phase == 3 and locked == False:
        counter += 1
        if counter <= len(trash):
            trash[(-1*counter)].hideturtle()
        else:
            text.clear()
            text.goto(0,325)
            text.write("Thank you! Now I am finally free!", False, align='center', font=('Arial', 20))
            text.goto(0,275)
            text.write("Press 'Space' to continue.", False, align='center', font=('Arial', 16))
            completeGame2 = True
            locked = True
            phase = 1
            loaded = False

# Selecting Game
def babyTurtle(x, y):
    global phase
    if phase == 1 and locked == False:
        phase = 2
        hideMenu()
        space()
def sisTurtle(x, y):
    global phase
    if phase == 1 and locked == False:
        phase = 3
        hideMenu()
        space()    
def mommyTurtle(x, y):
    global phase
    if phase == 1 and locked == False:
        phase = 4
        hideMenu()
        space()
            
# Trash Generation
def generateTrash():
    global trash
    for i in trash:
        i.hideturtle()
    if phase == 2:
        for i in range(len(trash)):
            trash[i].goto(random.randint(-350,350),random.randint(-250,190))
            trash[i].showturtle()
    elif phase == 3:
        for i in range(len(trash)):
            trash[i].goto(random.randint(-160,160),random.randint(-160,160))
            trash[i].showturtle()
    elif phase == 4:
        for i in range(len(trash)):
            trash[i].goto(random.randint(-350,350),random.randint(-350,350))
            trash[i].showturtle()

# Collision Detection    
def detect():
  global phase
  global loaded
  global locked
  global trash
  global counter

# Trash Detect
  if phase == 2:
   count = 0
   length = len(trash)
   while count < length:
     if (baby.distance(trash[count].xcor(), trash[count].ycor()) < 25):
      text.clear()
      text.write("Oh no! Try again!", False, align='center', font=('Arial', 20))
      locked = True
      baby.goto(-335, -335)
      generateTrash()
      locked = False
     count += 1

# Mom Detect
   if (baby.distance(mom.xcor(), mom.ycor()) < 75):
      locked = True
      text.clear()
      text.goto(0,320)
      text.write("You made it! Thank you!", False, align='center', font=('Arial', 24))
      text.goto(0,290)
      text.write("Press 'Space' to continue", False, align='center', font=('Arial', 24))
      global completeGame1
      completeGame1 = True
      loaded = False
      phase = 1

# Mom Detect Trash
  elif phase == 4:
   length = len(trash)
   for i in range(len(trash)):
     if (baby.distance(trash[i].xcor(), trash[i].ycor()) < 25):
      trash[i].hideturtle()
      trash[i].goto(0,400)
      counter += 1 

# Mom Cleaned All Trash
   if counter > 19:
      locked = True
      for i in trash:
          i.hideturtle()
      text.clear()
      text.goto(0,365)
      text.write("Thank you! Now I can clean the rest of this place!", False, align='center', font=('Arial', 24))
      text.goto(0,343)
      text.write("Press 'Space' to continue", False, align='center', font=('Arial', 24))
      global completeGame3
      completeGame3 = True
      loaded = False
      phase = 1

# random stamps spread on background
def randomStamp():
  shape = random.randint(1, 4)
  if shape == 1:
    t.shape("triangle")
  elif shape == 2:
    t.shape("square")
  elif shape == 3:
    t.shape("circle")
  elif shape == 4:
    t.shape("arrow")
  size = random.randint(1, 3)
  if size == 1:
    t.turtlesize(1.25)
  elif size == 2:
    t.turtlesize(0.75)
  elif size == 3:
    t.turtlesize(1)

      
# Screen Listening
s = turtle.Screen()
s.bgpic("water.gif")
s.listen()
s.onkey(space, "space")
s.onkey(up, "Up")
s.onkey(down, "Down")
s.onkey(left, "Left")
s.onkey(right, "Right")

s.onclick(click)

# Turtle background
t = turtle.Turtle()
t.speed("fastest")
t.penup() 
s.colormode(255)

for i in range(30):
  x = random.randint(-375, 375)
  y = random.randint(-375, 375)
  t.goto(x,y)
  r, g, b = 80, 150, 200
  t.pencolor(80, 150, 200)
  t.fillcolor(80, 150, 200)
  t.tilt(random.randint(0,360))
  randomStamp()
  t.stamp()
  s.update()



# Introduction with Mommy Turtle
mom = turtle.Turtle()
turtle.addshape("mom.gif")
mom.shape("mom.gif")
mom.penup()
mom.goto(0, -100)
        
# Text Writing Turtle
text = turtle.Turtle()
text.penup()
text.hideturtle()
text.goto(0, 100)
text.write("Hello, can you please help us? We are suffering from pollution!", False, align='center', font=('Arial', 20))
text.goto(0, 60)
text.write("Press 'Space' to help", False, align='center', font=('Arial', 14))

# Main Menu and Custom Shape Cache
turtle.addshape("check.gif")
turtle.addshape("arrow.gif")
turtle.addshape("game1.gif")
turtle.addshape("game2.gif")
turtle.addshape("game3.gif")

turtle.addshape("trash1.gif")
turtle.addshape("trash2.gif")
turtle.addshape("trash3.gif")
turtle.addshape("baby.gif")

turtle.addshape("momtiny.gif")
turtle.addshape("sis.gif")

trashpics = ["trash1.gif", "trash2.gif", "trash3.gif"]

victory = turtle.Turtle()
victory.hideturtle()     
victory.shape("arrow.gif")
victory.onclick(congratulations)
victory.penup()  
victory.goto(0, 180)

baby = turtle.Turtle()
baby.hideturtle()
baby.shape("baby.gif")
baby.penup()

sis = turtle.Turtle()
sis.hideturtle()
sis.shape("sis.gif")
sis.penup()

game1 = turtle.Turtle()
game1.hideturtle()
game1.shape("game1.gif")
game1.onclick(babyTurtle)
game1.penup()
game1.goto(-250, 0)

game2 = turtle.Turtle()
game2.hideturtle()       
game2.shape("game2.gif")
game2.onclick(sisTurtle)
game2.penup()

game3 = turtle.Turtle()
game3.hideturtle()     
game3.shape("game3.gif")
game3.onclick(mommyTurtle)
game3.penup()  
game3.goto(250, 0)


check1 = turtle.Turtle()
check1.hideturtle()
check1.penup()
check1.shape("check.gif")
check1.goto(-250, -150)

check2 = turtle.Turtle()
check2.hideturtle()
check2.penup()
check2.shape("check.gif")
check2.goto(0, -150)

check3 = turtle.Turtle()
check3.hideturtle()
check3.penup()
check3.shape("check.gif")
check3.goto(250, -150)

# Trash Pic Randomizer
trash = []
for i in range(20):
    trash.append(turtle.Turtle())
    trash[i].hideturtle()
    trash[i].shape(trashpics[random.randint(0,2)])
    trash[i].penup()
loaded = False

turtle.mainloop()

