import pygame
import sys
from PIL import Image
import os



def displayImage(screen, px, topleft, prior):
    # ensure that the rect always has positive width, height
    x, y = topleft
    width = pygame.mouse.get_pos()[0] - topleft[0]
    height = pygame.mouse.get_pos()[1] - topleft[1]
    if width < 0:
        x += width
        width = abs(width)
    if height < 0:
        y += height
        height = abs(height)

    # eliminate redundant drawing cycles (when mouse isn't moving)
    current = x, y, width, height
    if not (width and height):
        return current
    if current == prior:
        return current

    # draw transparent box and blit it onto canvas
    screen.blit(px, px.get_rect())
    im = pygame.Surface((width, height))
    im.fill((128, 128, 128))
    pygame.draw.rect(im, (32, 32, 32), im.get_rect(), 1)
    im.set_alpha(128)
    screen.blit(im, (x, y))
    pygame.display.flip()

    # return current box extents
    return (x, y, width, height)


def setup(path):
    px = pygame.image.load(path)
    screen = pygame.display.set_mode(px.get_rect()[2:])
    screen.blit(px, px.get_rect())
    pygame.display.flip()
    return screen, px


def mainLoop(screen, px):
    topleft = bottomright = prior = None
    n = 0
    while n != 1:
        for event in pygame.event.get():
            if event.type == pygame.MOUSEBUTTONUP:
                if not topleft:
                    topleft = event.pos
                else:
                    bottomright = event.pos
                    n = 1

                    left, upper, right, lower = (topleft + bottomright)

                    input_loc = '/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/CMT/051447670.jpg'
                    output_loc = 'out.png'

                    if right < left:
                        left, right = right, left
                    if lower < upper:
                        lower, upper = upper, lower

                    im = Image.open(input_loc)
                    im = im.crop((left, upper, right, lower))

                    print(left, upper, right, lower)
                    im.save(output_loc)

            elif event.type ==pygame.KEYDOWN:
                if event.key == pygame.K_1:
                    pygame.display.quit()
            elif event.type == pygame.QUIT:
                pygame.display.quit()

        if topleft:
            prior = displayImage(screen, px, topleft, prior)
            if n == 1:
                topleft = None
                n = 0

    return (topleft + bottomright)


if __name__ == "__main__":

    # import wx
    #
    # app = wx.PySimpleApp()
    # dialog = wx.MessageDialog(None, 'wxPython is awesome!', 'Dialog Box', wx.OK | wx.ICON_INFORMATION)
    # dialog.ShowModal()
    # dialog.Destroy()
    # app.MainLoop()

    import tkSimpleDialog
    from Tkinter import Tk, Label

    root = Tk()


    # root.mainloop()

    PATH = os.path.realpath("/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/CMT/")
    OUT = os.path.realpath("/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/crop/")

    if not os.path.exists(OUT):
        os.mkdir(OUT)

    fs = os.listdir(PATH)
    i = 0
    while i < len(fs):
        pygame.init()
        input_loc = os.path.join(PATH, fs[i])
        n = 0
        output_loc = 'out.png'
        im = Image.open(input_loc)

        screen, px = setup(input_loc)

        j = 0

        topleft = bottomright = prior = None
        while n != 1 and n !=2:
            for event in pygame.event.get():
                if event.type == pygame.MOUSEBUTTONUP:
                    if not topleft:
                        topleft = event.pos
                    else:
                        bottomright = event.pos
                        n = 1

                        left, upper, right, lower = (topleft + bottomright)

                        if right < left:
                            left, right = right, left
                        if lower < upper:
                            lower, upper = upper, lower

                        crop = im.crop((left, upper, right, lower))


                        name = tkSimpleDialog.askstring("label", "label")

                        if name is not None:
                            img_name = fs[i].split(".")
                            crop_name = img_name[0] + "_"+ name+"."+img_name[1]

                            output_loc = os.path.join(OUT, crop_name)
                            j += 1
                            crop.save(output_loc)

                elif event.type ==pygame.KEYDOWN:
                    if event.key == pygame.K_1:
                        i += 1
                        n = 2
                        pygame.display.quit()
                        break

                elif event.type == pygame.QUIT:
                    pygame.display.quit()

            if topleft:
                prior = displayImage(screen, px, topleft, prior)
                if n == 1:
                    topleft = None
                    n = 0
