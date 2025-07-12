import { StyleSheet, View, Text } from "react-native";
import { HambergerMenu, Location } from "iconsax-react-native";
import { SafeAreaView } from "react-native-safe-area-context";
import { theme } from "@/constants/theme";
import { Image } from "expo-image";

export default function Header() {
  return (
    <View
      style={{
        paddingHorizontal: 24,
        paddingTop: 8,
      }}
    >
      <View
        style={styles.header}>
        <View style={styles.headerLocation}>
          <View style={styles.headerLocationIcon}>
            <Location size="24" color="#fff" />
          </View>
          <View style={styles.headerLocationInfo}>
            <Text style={styles.headerLocationText}>Location</Text>
            <Text style={styles.headerLocationSubText}>Karachi, Pak</Text>
          </View>
        </View>
        <View style={styles.headerUser}>
            <HambergerMenu size="28" color="#fff" />
          <View style={styles.headerUserImage}>
            <Image source={{
              uri: "https://avatar.iran.liara.run/public"
            }}
            contentFit="cover"
            style={{width: "100%", height: "100%", objectFit: "cover"}} />
          </View>
        </View>
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  header: {
    flexDirection: "row",
    justifyContent: "space-between",
  },
  headerLocation: {
    flexDirection: "row",
    alignItems: "center",
    gap: 5,
  },
  headerLocationInfo: {
    gap: 2,
    justifyContent: "center",
  },
  headerLocationIcon: {
    padding: 14,
    borderColor: "rgba(255, 255, 255, 0.07)",
    borderWidth: 1,
    flexGrow: 0,
    borderRadius: 100,
    borderStyle: "solid",
  },
  headerLocationText: {
    color: "#8C8BA7",
    fontSize: 12,
    fontFamily: theme.font.medium,
  },
  headerLocationSubText: {
    color: "#fff",
    fontSize: 13,
    fontFamily: theme.font.bold,
  },
  wrapper: {},
  location: {},
  icon: {},
  headerUserMenu: {},
  headerUser: {
    flexDirection: "row",
    alignItems: "center",
    padding: 3,
    paddingLeft: 10,
    borderColor: "rgba(255, 255, 255, 0.07)",
    borderWidth: 1,
    borderRadius: 100,
    gap: 7,
  },
  headerUserImage: {
    width: 38,
    height: 38,
    objectFit: "cover",
    borderRadius: 100,
    overflow: "hidden",
  },
});
