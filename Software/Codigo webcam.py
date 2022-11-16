import cv2

cap = cv2.VideoCapture(0)
  
# lee la camara que se está utilizando


while(cap.isOpened()):
    
    result, image = cap.read()
    # guardar imagen
    cv2.imwrite("imagen.png", image)
    # muestra la imagen
    cv2.imshow("imagen", image)
    if (cv2.waitKey(1) == ord('s')):
        break


cap.release()
cv2.destroyAllWindows()


