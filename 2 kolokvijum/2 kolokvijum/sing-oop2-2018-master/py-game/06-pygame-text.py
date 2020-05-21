import pygame
"""
https://nerdparadise.com/programming/pygame/part5
"""


pygame.init()
screen = pygame.display.set_mode((800,600))
done = False

x,y = 30,30
color = (0,30, 100)

font = pygame.font.SysFont("Amiko", 20)
text = font.render("Singidunum", True, (100,100,100))



image = pygame.image.load('ball.png')

clock = pygame.time.Clock()
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
        if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
            done = True
        
    pressed = pygame.key.get_pressed()
    if pressed[pygame.K_UP]:
        y -= 3
    if pressed[pygame.K_DOWN]:
        y += 3
    if pressed[pygame.K_LEFT]:
        x -= 3
    if pressed[pygame.K_RIGHT]:
        x += 3
    

    screen.fill((0, 0, 0))
    pygame.draw.rect(screen, (255, 128, 255), pygame.Rect(100, 100, 60, 60))
    screen.blit(image, (x,y+160))



    pygame.draw.circle(screen, (200,0,0), (100, 150), 50, 2)
    pygame.draw.line(screen, color, (0,0), (200,200), 3)
    screen.blit(text, (100, 50))

    pygame.display.flip()
    clock.tick(100)