from PIL import Image

def convert_jpg_to_bmp(input_path, output_path):
    try:
        # Open the JPG image
        img = Image.open(input_path)

        # Save the image in BMP format
        img.save(output_path, 'BMP')

        print(f"Conversion successful. BMP image saved at: {output_path}")

    except Exception as e:
        print(f"Error: {e}")
i = 5
# # Example usage
# while(i<6):
#     # print('\"places ('+str(i)+').bmp\", ')
#     input_jpg_path = 'discover select ('+str(i)+').jpg'  # Replace with the actual JPG file path
#     # output_bmp_path = "../discover_sel/"+input_jpg_path.replace(".jpg", ".bmp")  # Specify the desired BMP output file path
#     output_bmp_path = "../discover_sel/"+"discover_1"+ str(i)+".bmp"
#     convert_jpg_to_bmp(input_jpg_path, output_bmp_path)
#     i=i+1
input_jpg_path = "manage.jpg"
# output_bmp_path = "../discover_sel/"+"discover"+str(i)+".bmp"
output_bmp_path = "../assets/"+input_jpg_path.replace(".jpg", ".bmp")
convert_jpg_to_bmp(input_jpg_path, output_bmp_path)