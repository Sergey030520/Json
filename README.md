# Json
Task 1. Information about the film from the film portal:

  Write down the detailed information about the movie in the form of a JSON file. Choose the picture you like on your favorite portal, analyze the information about it and compile a JSON dictionary.

The information must include: the country and date of creation of the film, the studio that conducted the shooting, the author of the script, the director and producer of the film. Be sure to add information about all the main characters and the actors who played them.

Task 2. Movie Data Analysis:

  Using the data model from task #1, create a JSON document, but now for five different films. The keys in this JSON database should be movie titles, and the values should already be dictionaries with information about the pictures.

Load the database into a C++ program for further analysis. Provide the following functionality: search for an actor by name (or surname) and output to the console the names of films in which the actor was filmed, and the role he played.

Task3. Company data model on Protobuf.

Create a data model for enterprise information. Required fields: year of foundation (32-bit integer), legal address (string) and name (string). Optional fields: type of activity (string), implementation of foreign economic activity (Boolean type)

Describe the model in proto2 and save it in a separate document with the proto extension. Then, based on the created document, generate C++ code using the protocol compiler.