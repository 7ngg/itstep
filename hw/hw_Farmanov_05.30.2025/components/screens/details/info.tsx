import { theme } from "@/constants/theme";
import { View, Text } from "react-native";

const Info = () => {
  return (
    <View>
      <View
        style={{
          flexDirection: "row",
          justifyContent: "space-around",
          alignItems: "center",
        }}
      >
        <Text
          style={{
            fontFamily: theme.font.medium,
            fontSize: 27,
            width: 180,
            color: "#fff",
          }}
        >
          Mercedes SL 63 AMG
        </Text>
        <View
          style={{
            borderColor: "#314FF6",
            borderWidth: 2,
            borderRadius: 20,
            justifyContent: "center",
            width: 125,
            height: 45,
            alignItems: "center",
            backgroundColor: "rgba(49, 79, 246, 0.1)",
          }}
        >
          <Text style={{ color: "#fff" }}>
            2500 AED/<Text style={{ color: "#8C8BA7" }}>day</Text>
          </Text>
        </View>
      </View>
      <View style={{ marginTop: 20, paddingHorizontal: 30 }}>
        <Text
          style={{
            fontFamily: theme.font.regular,
            fontSize: 16,
            color: "#8C8BA7",
          }}
        >
          The Mercedes SL 63 AMG is a sports car created using advanced
          technologies that have made it incredibly fast and powerful.
        </Text>
      </View>
      <View
        style={{
          borderWidth: 1,
          borderColor: "#8C8BA7",
          marginTop: 20,
          marginHorizontal: 30,
        }}
      />
    </View>
  );
};

export default Info;
