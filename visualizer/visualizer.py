import pygame
import sys
import re
import string
WINDOW_SIZE = 1200
WINDOW = pygame.display.set_mode((WINDOW_SIZE, WINDOW_SIZE))
BLUE = (0, 128, 255)
ORANGE = (255, 100, 0)
WHITE = (255, 255, 255)
WAIT = 50

def pause_game():
    while 1:
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    return
                if event.key == pygame.K_ESCAPE:
                    exit()

def print_plateau(map_y, map_x):
    i = 0
    global WAIT
    if map_y > map_x:
        rect_size = (WINDOW_SIZE - 200) / map_y - 5
    else:
        rect_size = (WINDOW_SIZE - 200) / map_x - 5
    offset = rect_size + 5
    y = (WINDOW_SIZE - (map_y * offset)) / 2
    while i < map_y:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                is_running = exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RIGHT:
                    if WAIT - 10 >= 0:
                        WAIT -= 10
                    print("program will wait", WAIT, "milliseconds between every new piece")
                if event.key == pygame.K_LEFT:
                    WAIT += 10
                    print("program will wait", WAIT, "milliseconds between every new piece")
                if event.key == pygame.K_SPACE:
                    if event.type == pygame.KEYDOWN:
                        print("||")
                        pause_game()
                        print('>')
                if event.key == pygame.K_ESCAPE:
                    exit()
        x = (WINDOW_SIZE - (map_x * offset)) / 2
        line = sys.stdin.readline()
        for char in line:
            if char == 'X' or char == 'x':
                pygame.draw.rect(WINDOW, (ORANGE), pygame.Rect(x, y, rect_size, rect_size))
            if char == 'O' or char == 'o':
                pygame.draw.rect(WINDOW, (BLUE), pygame.Rect(x, y, rect_size, rect_size))
            if char == '.':
                pygame.draw.rect(WINDOW, (WHITE), pygame.Rect(x, y, rect_size, rect_size))
            if char == '\n':
                y += offset
            if char == 'X' or char == 'x' or char == 'O' or char == 'o' or char == '\n' or char == '.':
                x += offset
        i += 1
    pygame.display.update()
    pygame.time.wait(WAIT)

def parse_input():
    for line in sys.stdin:
        tmp = line.split(" ")
        if tmp[0] == "Plateau":
            tmp[2] = tmp[2].rstrip(":\n")
            print_plateau(int(tmp[1]), int(tmp[2]))
        elif tmp[0] == "$$$":
            if tmp[2] == "p1":
                player1 = tmp[4]
                print(player1.rstrip("\n"), "IS PLAYER 1 (BLUE)")
            if tmp[2] == "p2":
                player2 = tmp[4]
                print(player2.rstrip("\n"), "IS PLAYER 2 (ORANGE)")
        elif tmp[0] == "==":
            if tmp[1] == "O":
                print("\n-----------=GAME FINISHED!=-----------\n")
                print(player1.rstrip("\n"), "SCORE:", tmp[3].rstrip("\n"))
            if tmp[1] == "X":
                print(player2.rstrip("\n"), "SCORE:", tmp[3].rstrip("\n"))



pygame.init()

def main():
    screen = pygame.display.set_caption('Quick Start')
    background = pygame.Surface((WINDOW_SIZE, WINDOW_SIZE))
    background.fill(pygame.Color('#000000'))
    logo = pygame.image.load("../visualizer/filler_logo.jpeg")
    pygame.display.set_icon(logo)
    is_running = True
    logo = pygame.transform.scale(logo, (WINDOW_SIZE - 200, WINDOW_SIZE - 200))
    WINDOW.blit(logo, (100, 100))
    pygame.display.update()
    while is_running:
        for event in pygame.event.get():
            pause_game()
            WINDOW.fill(0)
            pygame.display.update()
            if event.type == pygame.QUIT:
                is_running = False
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    is_running = False
            parse_input()
            pygame.display.update()
    pygame.display.update()

if __name__ == "__main__":
    main()
