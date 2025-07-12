import { theme } from "@/constants/theme";
import { ArrowLeft } from "iconsax-react-native";
import { View, Text, StyleSheet, Pressable } from "react-native";
import { Image } from "expo-image";

const Specifications = () => {
  return (
    <View style={{ paddingHorizontal: 30 }}>
      <Text
        style={{
          color: "white",
          fontSize: 18,
          fontFamily: theme.font.medium,
        }}
      >
        Specifications
      </Text>
      <View style={{ marginTop: 15 }}>
        <View style={{ flexDirection: "row", gap: 30 }}>
          <View style={styles.container}>
            <View style={styles.Icon}>
              <Image
                source={require("../../../assets/images/speedometer.png")}
                style={{
                  width: 20,
                  height: 20,
                  objectFit: "cover",
                }}
              />
            </View>
            <View style={styles.containerInfo}>
              <Text style={styles.Text}>Horsepower</Text>
              <Text style={styles.containerSubText}>585 hp</Text>
            </View>
          </View>
          <View style={styles.container}>
            <View style={styles.Icon}>
              <Image
                source={require("../../../assets/images/transmission.png")}
                style={{
                  width: 20,
                  height: 20,
                  objectFit: "cover",
                }}
              />
            </View>
            <View style={styles.containerInfo}>
              <Text style={styles.Text}>Transmission</Text>
              <Text style={styles.containerSubText}>Automatic</Text>
            </View>
          </View>
        </View>
      </View>
      <View
        style={{
          alignItems: "center",
          marginTop: 10,
        }}
      >
        <Pressable
          style={{
            backgroundColor: "#314FF6",
            borderRadius: 20,
            width: 327,
            height: 50,
            alignItems: "center",
            justifyContent: "center",
          }}
        >
          <Text
            style={{
              color: "#fff",
              fontSize: 16,
              fontFamily: theme.font.medium,
            }}
          >
            Book Now
          </Text>
        </Pressable>
      </View>
    </View>
  );
};

export default Specifications;

const styles = StyleSheet.create({
  container: {
    flexDirection: "row",
    alignItems: "center",
    gap: 18,
  },
  containerInfo: {
    gap: 2,
    justifyContent: "center",
  },
  Icon: {
    padding: 18,
    borderColor: "rgba(255, 255, 255, 0.07)",
    borderWidth: 1,
    flexGrow: 0,
    borderRadius: 100,
    borderStyle: "solid",
  },
  Text: {
    color: "#8C8BA7",
    fontSize: 16,
    fontFamily: theme.font.regular,
  },
  containerSubText: {
    color: "#fff",
    fontSize: 18,
    fontFamily: theme.font.medium,
  },
});
