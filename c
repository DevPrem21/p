from tensorflow import keras
from tensorflow.keras import layers
import numpy as np
import matplotlib.pyplot as plt

(x_train, _), (x_test, _) = keras.datasets.mnist.load_data()

x_train = x_train / 255.0
x_test = x_test / 255.0

x_train = x_train.reshape(-1, 784)
x_test = x_test.reshape(-1, 784)

input_img = keras.Input(shape=(784,))
encoded = layers.Dense(128, activation='relu')(input_img)
latent = layers.Dense(2, activation='relu')(encoded)
decoded = layers.Dense(128, activation='relu')(latent)
output = layers.Dense(784, activation='sigmoid')(decoded)

autoencoder = keras.Model(input_img, output)
autoencoder.compile(optimizer='adam', loss='mse')

autoencoder.fit(x_train, x_train, epochs=5, batch_size=256)

decoded_imgs = autoencoder.predict(x_test)

i = np.random.randint(0, len(x_test))

plt.subplot(1,2,1)
plt.imshow(x_test[i].reshape(28,28), cmap='gray')

plt.subplot(1,2,2)
plt.imshow(decoded_imgs[i].reshape(28,28), cmap='gray')

plt.show()
