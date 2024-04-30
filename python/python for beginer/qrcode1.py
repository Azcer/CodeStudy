import qrcode as qr

Hello = qr.QRCode(box_size = 10 , border = 2)
Hello.make()
Hello.add_data("Hello, Miss Peace")
qr_image = Hello.make_image()
qr_image.show()
qr_image.save("D:/code/Hello.png")
