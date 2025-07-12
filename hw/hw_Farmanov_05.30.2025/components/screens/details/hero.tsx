import { Image } from "expo-image";
import { StyleSheet, View, Text } from "react-native";

const Hero = () => {
  return (
    <View>
      <View style={{ alignItems: "center", marginBottom: 20 }}>
        <Image
          source={require("../../../assets/images/mercedesHero.png")}
          style={{
            minWidth: 400,
            height: 250,
            borderRadius: 10,
            objectFit: "contain",
          }}
        />
      </View>
      <View
        style={{
          flexDirection: "row",
          justifyContent: "space-evenly",
          paddingVertical: 10,
        }}
      >
        <Image
          source={require("../../../assets/images/mercedes1.png")}
          style={{
            width: 75,
            height: 62,
            borderRadius: 10,
            objectFit: "contain",
          }}
        />
        <View
          style={{
            borderRadius: 10,
            borderWidth: 1,
            borderColor: "#314FF6",
          }}
        >
          <Image
            source={require("../../../assets/images/mercedesHero.png")}
            style={{
              width: 75,
              height: 62,
              borderRadius: 10,
              objectFit: "contain",
            }}
          />
        </View>
        <Image
          source={require("../../../assets/images/mercedes3.png")}
          style={{
            width: 75,
            height: 62,
            borderRadius: 10,
            objectFit: "contain",
          }}
        />
        <Image
          source={require("../../../assets/images/mercedes4.png")}
          style={{
            width: 75,
            height: 62,
            borderRadius: 10,
            objectFit: "cover",
          }}
        />
      </View>
      <View
        style={{
          flexDirection: "row",
          alignItems: "center",
          justifyContent: "center",
          gap: 2,
          marginTop: 10,
        }}
      >
        <View
          style={{
            backgroundColor: "white",
            height: 5,
            width: 12,
            borderRadius: 10,
          }}
        />
        <View
          style={{
            backgroundColor: "gray",
            height: 5,
            width: 5,
            borderRadius: 10,
          }}
        />
        <View
          style={{
            backgroundColor: "gray",
            height: 5,
            width: 5,
            borderRadius: 10,
          }}
        />
      </View>
    </View>
  );
};

export default Hero;

const styles = StyleSheet.create({});
