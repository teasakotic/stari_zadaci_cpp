import pygame
"""
https://nerdparadise.com/programming/pygame/part1
"""


pygame.init()
screen = pygame.display.set_mode((800,600))
done = False

x,y = 30,30

clock = pygame.time.Clock()
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
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
    pygame.draw.rect(screen, (255, 128, 255), pygame.Rect(x, y, 60, 60))


    pygame.display.flip()
    clock.tick(100)
