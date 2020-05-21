import pygame
"""
https://nerdparadise.com/programming/pygame/part5
"""


pygame.init()
screen = pygame.display.set_mode((800,600))
done = False

points = []

clock = pygame.time.Clock()
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
        if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
            done = True
        
        if event.type  = pygame.MOUSEBUTTONDOWN:
            points.append(event.pos)

    screen.fill((0, 0, 0))

    pygame.draw.line(screen, color, (0,0), (200,200), 3)

    pygame.display.flip()
    clock.tick(100)