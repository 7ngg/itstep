insert into ManufacturingCountries (country_name) values
('USA'),
('Germany'),
('Japan'),
('South Korea'),
('China');

insert into FuelTypes (fuel_type) values
('Gasoline'),
('Diesel'),
('Electric'),
('Hybrid');

insert into BodyTypes (body_type) values
('Sedan'),
('SUV'),
('Hatchback'),
('Coupe');

insert into Colors (color_name) values
('Red'),
('Blue'),
('Black'),
('White'),
('Silver');

insert into Cars (brand, model, year, fuel_type_id, body_type_id, color_type, image_link) values
('Toyota', 'Camry', '2022-01-01', 3, 1, 1, 'link_to_image1'),
('Honda', 'Civic', '2023-01-01', 1, 2, 2, 'link_to_image2'),
('BMW', 'X5', '2022-01-01', 2, 2, 3, 'link_to_image3'),
('Tesla', 'Model 3', '2023-01-01', 3, 3, 4, 'link_to_image4');

insert into Users (username, password, email) values
('user1', 'password1', 'user1@example.com'),
('user2', 'password2', 'user2@example.com'),
('user3', 'password3', 'user3@example.com');

insert into Sellers (user_id, company_name, contact_number, country_id, rating) values
(1, 'ABC Motors', '123-456-7890', 2, 4),
(2, 'XYZ Cars', '987-654-3210', 1, 3),
(3, 'Car World', '555-123-4567', 3, 5);

insert into ProductList (car_id, seller_id, price, quantity) values
(1, 1, 25000, 5),
(2, 2, 22000, 3),
(3, 3, 40000, 2),
(4, 1, 50000, 1);
