import { theme } from "@/constants/theme";
import { SearchNormal1 } from "iconsax-react-native";
import { View, Text, StyleSheet, TextInput } from "react-native";

const Hero = () => {
  return (
    <View
      style={{
        gap: 25,
      }}
    >
      <View
        style={{
          gap: 25,
        }}
      >
        <View
          style={{
            maxWidth: 275,
          }}
        >
          <View style={{ flexDirection: "row", alignItems: "center", gap: 10 }}>
            <Text style={styles.text}>Explore new</Text>
            <View
              style={{
                flexDirection: "row",
                backgroundColor: "white",
                height: 1.5,
                flexGrow: 1,
                minWidth: 100,
              }}
            />
          </View>
          <Text style={styles.text}>destinations with ease!</Text>
        </View>
      </View>
      <View style={styles.inputWrapper}>
        <SearchNormal1
          color="rgba(255, 255, 255, 0.5)"
          style={{
            position: "absolute",
            left: 15,
          }}
          size="25"
        />
        <TextInput
          placeholder="Search your dream car..."
          placeholderTextColor={"rgba(255, 255, 255, 0.5)"}
          style={{
            color: "white",
          }}
        />
      </View>
    </View>
  );
};

export default Hero;

const styles = StyleSheet.create({
  text: {
    fontFamily: theme.font.medium,
    fontSize: 27,
    color: "#fff",
  },
  inputWrapper: {
    width: "100%",
    height: 54,
    alignItems: "center",
    flexDirection: "row",
    borderRadius: 25,
    paddingRight: 10,
    paddingLeft: 48,
    position: "relative",
    paddingHorizontal: 15,
    borderWidth: 1,
    borderColor: "rgba(255, 255, 255, 0.07",
    backgroundColor: "rgba(255, 255, 255, 0.04)",
  },
});
