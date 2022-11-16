import cv2, time

cap = cv2.VideoCapture(0)
contador = 1


for contador in range(1,5):

    name_1="img"
    c_name=str(contador)
    name=name_1+c_name+".jpg"
    
    result, image = cap.read()
    # guardar imagen
    cv2.imwrite(name, image)
    time.sleep(2)
    contador== contador + 1



cap.release()
cv2.destroyAllWindows()


