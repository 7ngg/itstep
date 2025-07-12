import { theme } from "@/constants/theme";
import { ArrowRight } from "iconsax-react-native";
import { View, Text, FlatList, useWindowDimensions } from "react-native";
import { Image } from "expo-image";

const CAR_BRANDS = [
  {
    id: "1",
    name: "Tesla",
    src: "https://www.carlogos.org/car-logos/tesla-logo-2007-full-640.png",
  },
  {
    id: "2",
    name: "BMW",
    src: "https://www.carlogos.org/car-logos/bmw-logo-2020-gray.png",
  },
  {
    id: "3",
    name: "Toyota",
    src: "https://www.carlogos.org/car-logos/toyota-logo-2020-europe-640.png",
  },
];

interface ItemType {
  src: string;
  name: string;
}

const CarBrands = () => {
  const { width } = useWindowDimensions();
  const renderItem = ({ item }: { item: ItemType }) => (
    <View
      style={{
        width: width / 3 - 24,
        height: 130,
        backgroundColor: "rgba(255, 255, 255, 0.04)",
        borderColor: "rgba(255, 255, 255, 0.07)",
        borderWidth: 1,
        borderRadius: 10,
        padding: 10,
        alignItems: "center",
        justifyContent: "center",
        gap: 8,
      }}
    >
      <Image
        contentFit="contain"
        source={{ uri: item.src }}
        style={{
          width: 64,
          height: 64,
        }}
      />
      <Text
        style={{
          fontFamily: theme.font.medium,
          fontSize: 14,
          color: "#fff",
        }}
      >
        {item.name}
      </Text>
    </View>
  );

  return (
    <View
      style={{
        gap: 22,
      }}
    >
      <View style={{ flexDirection: "row", justifyContent: "space-between" }}>
        <Text
          style={{
            fontFamily: theme.font.medium,
            fontSize: 18,
            color: "white",
          }}
        >
          Browse by brands
        </Text>
        <ArrowRight size="25" color="white" />
      </View>
      <FlatList
        horizontal
        contentContainerStyle={{
          gap: 13,
        }}
        renderItem={renderItem}
        data={CAR_BRANDS}
      />
    </View>
  );
};

export default CarBrands;
